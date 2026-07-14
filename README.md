# BSQ

## Header File (`bsq.h`)
- Yazdığım tüm C dosyaları birbiri ile bu dosya ile konuşur, verileri hangi formatta tutacağımızı söyleyen dosya.

- Derleme hatalarını engellemek için #ifndef: Derleyici yanlışlıkla dosyayı iki kez okursa tanım tekrarı diye bir hata verir. Bu aslında bi koruma, dosyayı bir kere dahil etmek demek.

- Çok parametre çıkacağı için bi tane struct oluşturdum ve değişkenleri buraya tanımladım, yoksa sonra okunmuyor.

- t_square struct'ında da bulduğumuz en büyük karenin sağ alt köşe koordinatlarını (r, c) ve boyutunu (size) tek bir yapıda paket ettim, fonksiyonlar arasında taşımak daha kolay olacak.

### s_map yapısı

- row / cols: haritanın sınırları, seg fault yiyip kalmayalım sonra :D

- empty / obstacle(engel) / full: haritanın dinamik karakterleri sabit olarak . veya o yazmakla uğraşamayız, çünkü dökümantasyonda bunlar değişebilir diye belirtmiş adamlar, değişkende tutmak lazım.

- grid: zaten adından belli haritanın kendisi, bellekte dinamik olarak açacağımız iki boyutlu karakter matrisi.

- s_square: şimdi, en büyük kareyi bulunca, o karenin büyüklüğünü ve haritanın neresinde bittiğini hafızada tutmamız lazım, bu struct ona yarıyor, minimal bir şey.

- Fonksiyon prototipleri: ft_utils.c, ft_solver.c, ft_draw.c içinde yazacağım fonksiyonları buraya şimdiden yazdım ki daha sonra unutup mal gibi derleme hatası ile uğraşmayayım.

---

## Kendi Kendime Çalışma Notları

### - "Neden bsq.h'ta struct'ın sonuna `;` koydun ama diğer yerlerde yok?"
- Struct tanımlarken derleyiciye "ben yeni bir veri tipi oluşturuyorum" diyorum. C dilinde bu tip tanımlamalarının sonuna `;` koymak zorunlu, yoksa derleyici nerede bittiğini anlamıyor ve doğrudan syntax hatası fırlatıyor. `typedef struct s_map { ... } t_map;` derken o en sondaki noktalı virgül bu yüzden hayati.

### - "Kodda bazı yerlerde `.` (nokta) kullanmışsın, bazı yerlerde `->` (ok işareti) kullanmışsın. Farkı ne?"
- Mevzu tamamen belleğe nasıl eriştiğimizle alakalı.
- Eğer struct'ın kendisi elimdeyse (yani pointer değilse) direkt `.` ile erişirim. Mesela `ft_solve_bsq` içinde `t_square max;` diye normal bir değişken tanımladım. Pointer falan değil. O yüzden `max.size = 0;` diyorum.
- Ama eğer elimdeki şey bir pointer ise, yani struct'ın adresiyse, o zaman `->` kullanmak zorundayım. Mesela `ft_update_max` fonksiyonuna `t_square *max` şeklinde pointer gönderdik. İçeride onun değerine erişmek için `max->size` yazıyorum. Bu aslında `(*max).size` yazmanın daha fiyakalı ve kısa yoludur.

### - "Neden `char **grid` kullandın da düz `char *` kullanmadın?"
- Çünkü haritamız iki boyutlu (satırlar ve sütunlar var). `char **` demek, "pointer'ların pointer'ı" (çift pointer) demek.
- İlk pointer satırların adreslerini tutan bir dizi, o satırların her birinin gösterdiği diğer pointer ise o satırdaki karakterleri (sütunları) tutuyor. Bellekten dinamik yer ayırırken önce satırlar için yer istiyoruz, sonra her satırın içine sütunları tek tek bağlıyoruz.

### - "Burada niye `int **dp` kullandın, solver'da niye `int` matrisi var?"
- Haritayı okurken karakterlerle (`char`) işimiz var ama dinamik programlama yaparken her hücredeki en büyük kare boyutunu sayılarla (`int`) saklamamız gerekiyor. `int **dp` tablosu, haritadaki her koordinat için o hücrede bitebilecek maksimum kare boyutunun sayısal değerini tutuyor. `char` yapsaydık en fazla 127 boyutundaki kareyi tutabilirdik (çünkü signed char sınırı bu), ama `int` kullanarak devasa haritaları bile sorunsuz hesaplayabiliyoruz.

---

### ft_utils.c

- Ekrana yazmak için gerekli yardımcı fonksiyonlar işte putchar putstr vs.

- ft_min_of_three: şimdi mantıken bir hücrenin sol, üst ve sol-üst çaprazındaki değerlerin en küçüğünü bulmak zorundayız. Kodda karışık durmasın diye buraya yazdım.

- ft_min_of_three: önce a ile b'yi karşılaştıracak, küçük olanı min değişkenine atacak. Sonra min ile c'yi karşılaştırıp, en küçük değeri tek seferde dönüyor.

---

### ft_solver.c

- ft_free_dp: bu fonksiyon dinamik olarak açtığımız o `int **dp` tablosunu satır satır temizliyor. Norm kuralında "bir dosyada en fazla 5 fonksiyon olabilir" diye bir kural olduğu için bunu `ft_utils.c` içine taşıdım, solver'da yer açılsın diye. Yoksa normdan kalırdık.

- ft_allocate_dp: bu fonksiyon bize dinamik programlama tablosu için hafızada yer açıyor.
  - Burada neden `int **` dönüyor? Çünkü bize iki boyutlu bir dinamik tablo lazım. `malloc` hata verirse hafıza sızıntısı (leak) olmasın diye o ana kadar açtığı tüm satırları `ft_free_dp` ile temizleyip `NULL` döndürüyor. Çok güvenli!

- ft_update_max: o ana kadar bulduğumuz en büyük kareyi güncelleyen fonksiyon.
  - *Kritik Soru:* "Eğer iki tane aynı boyutta en büyük kare varsa hangisini alıyor?"
  - *Cevap:* Tabii ki ilk bulduğumuzu (yani en üst sol taraftakini). Çünkü koşulu `size > max->size` olarak yazdım. Yani yeni bulduğumuz karenin boyutu, elimizdeki rekoru **kesinlikle geçmek zorunda**. Eşitlik durumunda güncellenmediği için ilk bulduğumuz kare şampiyon kalıyor!

- ft_procces_cell: haritadaki her bir hücreyi tek tek işleyen asıl formülümüz burada dönüyor.
  - Eğer hücre engelse (`obstacle`), orada kare falan bitemez, direkt `0` yazıyoruz.
  - Eğer ilk satır veya ilk sütundaysak (`r == 0 || c == 0`), arkamızda başka komşu olmadığı için en fazla `1` boyutunda kare yapabiliriz.
  - Diğer durumlarda sol, üst ve sol-üst çapraz komşulardan en küçüğünü bulup (`ft_min_of_three`), üzerine `1` ekliyoruz. *Neden en küçüğü?* Çünkü kare her taraftan eşit büyümek zorunda, bir kenarı bile engelle kesilse büyümesi durur (darboğaz mantığı).
  - *TOO_MANY_ARGS Hatasının Çözümü:* Norm kuralına göre bir fonksiyona en fazla 4 parametre gönderebiliyoruz. Burada başta `map`, `dp`, `r`, `c` ve `max` olmak üzere 5 parametre gönderiyordum ve Norm hata verdi. Ben de `r` ve `c` koordinatlarını ayrı ayrı göndermek yerine, zaten elimizde olan `t_square` struct'ından geçici bir `curr` değişkeni oluşturup koordinatları onun içine paketledim. Böylece parametre sayısını 4'e düşürüp Norm kuralına tam uyum sağladım.

- ft_solve_bsq: tüm bu operasyonu yöneten, hafızayı başlatan, döngüyü döndüren, en son ekran çıktısını verip açtığı tüm belleği sisteme geri veren (`free`) ana çözücü fonksiyonumuz.
