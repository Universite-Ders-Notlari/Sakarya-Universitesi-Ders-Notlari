-- phpMyAdmin SQL Dump
-- version 4.5.1
-- http://www.phpmyadmin.net
--
-- Anamakine: 127.0.0.1
-- Üretim Zamanı: 22 Nis 2017, 11:10:13
-- Sunucu sürümü: 10.1.16-MariaDB
-- PHP Sürümü: 7.0.9

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Veritabanı: `webtek`
--
DROP DATABASE `webtek`;
CREATE DATABASE IF NOT EXISTS `webtek` DEFAULT CHARACTER SET utf8 COLLATE utf8_turkish_ci;
USE `webtek`;

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `etkinlikler`
--

DROP TABLE IF EXISTS `etkinlikler`;
CREATE TABLE `etkinlikler` (
  `id` int(11) NOT NULL,
  `tarih` date NOT NULL,
  `baslik` varchar(64) COLLATE utf8_turkish_ci NOT NULL,
  `icerik` text COLLATE utf8_turkish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `etkinlikler`
--

INSERT INTO `etkinlikler` (`id`, `tarih`, `baslik`, `icerik`) VALUES
(1, '2017-04-26', '2. Kısa Sınav', 'Online yapılacak 2. kısa sınava mutlaka katılınızzzz. Online yapılacak 2. kısa sınava mutlaka katılınızzzz.Online yapılacak 2. kısa sınava mutlaka katılınızzzz.Online yapılacak 2. kısa sınava mutlaka katılınızzzz.Online yapılacak 2. kısa sınava mutlaka katılınızzzz.Online yapılacak 2. kısa sınava mutlaka katılınızzzz.Online yapılacak 2. kısa sınava mutlaka katılınızzzz.'),
(2, '2017-09-04', '1. Kısa Sınav', 'Online yapılacak 12. kısa sınava mutlaka katılınızzzz. Online yapılacak 2. kısa sınava mutlaka111111'),
(3, '2017-03-01', 'as dasd asd', 'asd asd asd asd  asd jklsdhfklsdjfgsdfh gsdlfkj ghsdlfkjgh sdlkfj ghsdklfj ghsdklfj ghlksdjfgh klsdjfhjksdfhgkljsdhfcbvmösdfjklgh dfjksdf vsdfgbdfg');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `kullanicilar`
--

DROP TABLE IF EXISTS `kullanicilar`;
CREATE TABLE `kullanicilar` (
  `id` int(11) NOT NULL,
  `email` varchar(64) COLLATE utf8_turkish_ci NOT NULL,
  `parola` varchar(64) COLLATE utf8_turkish_ci NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `kullanicilar`
--

INSERT INTO `kullanicilar` (`id`, `email`, `parola`) VALUES
(1, 'heski@sakarya.edu.tr', 'eski'),
(2, 'umit@sakarya.edu.tr', 'kocabicak'),
(3, 'ntasbasi@sakarya.edu.tr', 'tasbasi'),
(4, 'fatihadak@sakarya.edu.tr', 'adak');

-- --------------------------------------------------------

--
-- Tablo için tablo yapısı `menuler`
--

DROP TABLE IF EXISTS `menuler`;
CREATE TABLE `menuler` (
  `id` int(11) NOT NULL,
  `baslik` varchar(32) COLLATE utf8_turkish_ci NOT NULL,
  `link` varchar(64) COLLATE utf8_turkish_ci NOT NULL,
  `sira` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_turkish_ci;

--
-- Tablo döküm verisi `menuler`
--

INSERT INTO `menuler` (`id`, `baslik`, `link`, `sira`) VALUES
(1, 'Hakkımda', '?page=hakkimda', 1),
(2, 'İletişim', '?page=iletisim', 3),
(3, 'Galeri', '?page=galeri', 2);

--
-- Dökümü yapılmış tablolar için indeksler
--

--
-- Tablo için indeksler `etkinlikler`
--
ALTER TABLE `etkinlikler`
  ADD PRIMARY KEY (`id`);

--
-- Tablo için indeksler `kullanicilar`
--
ALTER TABLE `kullanicilar`
  ADD PRIMARY KEY (`id`);

--
-- Tablo için indeksler `menuler`
--
ALTER TABLE `menuler`
  ADD PRIMARY KEY (`id`);

--
-- Dökümü yapılmış tablolar için AUTO_INCREMENT değeri
--

--
-- Tablo için AUTO_INCREMENT değeri `etkinlikler`
--
ALTER TABLE `etkinlikler`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
--
-- Tablo için AUTO_INCREMENT değeri `kullanicilar`
--
ALTER TABLE `kullanicilar`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- Tablo için AUTO_INCREMENT değeri `menuler`
--
ALTER TABLE `menuler`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
