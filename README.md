# BSQ Projesi - Yapılacaklar Listesi

Verilen alandaki mümkün olan en büyük kareyi hesaplayan ve yazdıran bir program geliştirmek.

## Genel Amaç

- [ ] Engellerden kaçınarak bir harita üzerindeki en büyük kareyi bulan bir program yaz.

## Girdi / Dosya İşleme

- [ ] Harita bilgisini içeren bir dosyayı, programa argüman olarak alabilecek şekilde yapılandır.
- [ ] Programın 1 ile n arasında dosya işleyebilmesini sağla (birden fazla dosya argüman olarak verilebilmeli).
- [ ] Herhangi bir argüman verilmediğinde, standart girdiden (stdin) tek bir haritayı okuyabilecek şekilde destek ekle (örn. `./bsq < map` veya `cat map | ./bsq`).
- [ ] Birden fazla dosya/harita işlendiğinde, iki çözüm (veya hata mesajı) arasına boş bir satır ekle.

## Dosya Formatının Okunması

- [ ] Dosyanın ilk satırından şu bilgileri ayrıştır:
  - [ ] Haritadaki satır sayısı (geçerli herhangi bir pozitif tam sayı olabilir).
  - [ ] "Boş" karakter.
  - [ ] "Engel" karakteri.
  - [ ] "Tam/Dolu" karakter.
- [ ] "Boş", "engel" ve "dolu" karakterlerinin satırın son 3 karakteri olduğunu, bunlardan önceki karakterlerin satır sayısını temsil ettiğini dikkate alarak ayrıştırma mantığını kur.
- [ ] Boşluk karakterinin veya rakamların bu son 3 karakterin parçası olabileceği durumları doğru şekilde ele al.
- [ ] Haritanın "boş" ve "engel" karakterlerinden oluşan satırlardan meydana geldiğini işleyecek şekilde harita okuma mantığını yaz.

## Geçerlilik Kontrolleri

- [ ] İlk satırın geçerli bir pozitif sayı ile başlayıp başlamadığını kontrol et.
- [ ] İlk satırda tam olarak üç farklı yazdırılabilir karakterin ve ardından bir satır sonu karakterinin bulunduğunu doğrula.
- [ ] Haritada en az bir satır ve her satırda en az bir hücre olduğunu kontrol et.
- [ ] Satırların standart satır sonu karakteriyle ayrıldığını doğrula.
- [ ] Haritadaki karakterlerin yalnızca ilk satırda tanımlanan karakterlerden (boş, engel, dolu) oluştuğunu kontrol et.
- [ ] Geçersiz bir dosya veya harita tespit edildiğinde:
  - [ ] Standart çıktıya bir harita hata mesajı yazdır.
  - [ ] Hata mesajının ardından bir satır sonu karakteri ekle.
  - [ ] Varsa bir sonraki dosyanın işlenmesine devam et.

## Algoritma / Çözüm Mantığı

- [ ] Haritadaki en büyük kareyi bulacak algoritmayı tasarla ve uygula (örn. dinamik programlama yaklaşımı).
- [ ] Birden fazla en büyük kare çözümü olduğunda:
  - [ ] Haritanın en üstüne en yakın olan kareyi seç.
  - [ ] Eşitlik durumunda en solda yer alan kareyi seç.
- [ ] Seçilen kareye karşılık gelen "boş" karakterleri "dolu" karakterlerle değiştir.

## Çıktı

- [ ] Bulunan en büyük kareyi haritanın üzerine işlenmiş şekilde standart çıktıya yazdır.

## Derleme / Makefile

- [ ] Projeyi derleyen geçerli bir Makefile oluştur.
- [ ] Makefile'ın gereksiz yeniden bağlama (relink) işlemi yapmadığından emin ol.

## Notlar

- Sonuç görsel olarak kare gibi görünmese de (örneğin engellerin görüntüyü bozması nedeniyle), aslında matematiksel olarak bir karedir.
