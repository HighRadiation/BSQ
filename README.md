# BSQ
- Verilen alandaki mümkün olan en büyük kareyi hesaplayan ve yazdıran bir program.
- Bu projenin amacı, engellerden kaçınarak bir harita üzerindeki en büyük kareyi bulmaktır.
- Haritayı içeren bir dosya sağlanacaktır. Bu dosya, programınıza bir argüman olarak iletilmelidir.
- Dosyanın ilk satırı, haritanın nasıl okunacağına dair bilgiler içerir:
	∗ Haritadaki satır sayısı; geçerli herhangi bir tam sayı olabilir.
	∗ “Boş” karakter.
	∗ "Engel" karakteri.
	∗ "Tam" karakter.
- "Boş", "engel" ve "dolu" karakterleri satırın son 3 karakteridir; bunların önündeki diğer tüm karakterler ise satır sayısını temsil eder.
- Harita, "boş" karakterler ve "engel" karakterleri içeren satırlardan oluşur.
- Programın görevi, mümkün olan en büyük kareyi temsil etmek amacıyla bazı "boş" karakterleri "dolu" karakterlerle değiştirmektir.
- Birden fazla çözümün bulunduğu durumlarda, haritanın en üst kısmına en yakın olan kareyi, ardından da en solda yer alan kareyi temsil etmeyi seçeceğiz.
- Programınız, parametre olarak 1 ila n arasında dosyayı işleyebilmelidir.
- Programınız argüman olarak birden fazla dosya aldığında, iki farklı çözüm veya harita hata mesajı arasında boş bir satır yer alacaktır.
- Herhangi bir argüman verilmediği takdirde, programınız yönlendirme (redirection) yoluyla standart girdiden tek bir harita okuyabilmelidir; örneğin: `./bsq < map` veya `cat map | ./bsq`. Bu durumda argüman olarak bir dosya adı belirtilmez; haritanın içeriği doğrudan standart girdi (stdin) üzerinden sağlanır.
- Projenizi derleyen geçerli bir Makefile'a sahip olmalısınız. Makefile'ınız yeniden bağlama (relink) işlemi yapmamalıdır.
### Geçerli dosya tanımı:
- İlk satır geçerli bir pozitif sayıyla başlamalı; bunu üç farklı yazdırılabilir karakter ve satır sonu karakteri takip etmelidir.
- Boşluk karakterinin veya rakamların, satırın son 3 karakterinin bir parçası olabileceğine dikkat edin.
- Harita üzerinde, en az bir hücreden oluşan en az bir sıra bulunmaktadır.
- Satırlar, alışılagelmiş satır sonu karakteriyle ayrılır.
- Haritadaki karakterler, yalnızca ilk satırda tanıtılanlar olabilir.
### N
- Geçersiz bir dosya veya harita durumunda, programınız standart çıktıya bir harita hatası mesajı ve ardından bir satır sonu karakteri yazdırmalıdır. Daha sonra programınız, varsa bir sonraki dosyaya geçecektir.

## Gerçekten de bir kare. Her ne kadar görsel olarak öyle görünmese de.

