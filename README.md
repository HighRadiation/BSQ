# BSQ

## Header File
- Yazdığım tüm C dosyaları birbiri ile bu dosya ile konuşur, verileri hangi formatta tutacağımızı söyleyen dosya.

- Derleme hatalarını engellemek için #ifndef: Derleyici yanlışlıkla dosyayı iki kez okursa tanım tekrarı diye bir hata verir. Bu aslında bi koruma, dosyayı bir kere dahil etmek demek.

- Çok parametre çıkacağı için bi tane struct oluşturdum ve değişkenleri buraya tanımladım, yoksa sonra okunmuyor.

- t_square struct'ın da bulduğumuz en büyük karenin sağ alt köşe koordinatlarını (r, c) ve boyutunu (size) tek bir yapıda paket ettim, fonksiyonlar arasında taşımak daha kolay olacka.

### s_map yapısı

- row / cols: haritanın sınırları, seg fault yiyip kalmayalım sonra :D

- empty / obstacle(engel) / full: haritanın dinamik karakterleri sabit olarak . veya o yazmakla uğraşamayız, çünkü dökümantasyonda bunlar değişebilir diye belirtmiş adamlar, değişkende tutmak lazım.

- grid: zaten adından belli haritanın kendisi, bellekte dinamik olarak açacağımız iki boyutlu karakter matrisi.

- s_square: şimdi, en büyük kareyi bulunca, o karenin büyüklüğünü ve haritanın neresinde bittiğini hafızada tutmamız lazım, bu struct ona yarıyor, minimal bir şey.

- Fonksiyon prototipleri: ft_utils.c, ft_solver.c, ft_draw.c içinde yazacağım fonksiyonları buraya şimdiden yazdım ki daha sonra unutup mal gibi derleme hatası ile uğraşmayayım.

### ft_utils.c

- Ekrana yazmak için gerekli yardımcı fonksiyonlar işte putchar putstr vs.

- ft_min_of_three: şimdi mantıken bir hücrenin sol, üst ve sol-üst çaprazında ki değerlerin en küçüğünü bulmak zorundayız. Kodda karışı o yüzden buraya yazdım.

- ft_min_of_three: önce a ile b'yi karşılaştıracak, küçük olanı min değişkenine atacak. Sonra min ile c'yi karşılaştırıp, en küçük değeri tek seferde dönüyor.









