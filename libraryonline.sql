-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Dec 10, 2024 at 10:08 AM
-- Wersja serwera: 10.4.32-MariaDB
-- Wersja PHP: 8.0.30

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `libraryonline`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `ksiazki`
--

CREATE TABLE `ksiazki` (
  `id_produktu` int(11) NOT NULL,
  `tytul` varchar(255) NOT NULL,
  `seria` varchar(255) DEFAULT NULL,
  `autor` varchar(255) NOT NULL,
  `wydawnictwo` varchar(255) DEFAULT NULL,
  `jezyk_wydania` varchar(50) NOT NULL,
  `jezyk_oryginalu` varchar(50) DEFAULT NULL,
  `liczba_stron` int(11) DEFAULT NULL,
  `numer_wydania` int(11) DEFAULT NULL,
  `data_premiery` date DEFAULT NULL,
  `rok_wydania` int(11) DEFAULT NULL,
  `forma` enum('ebook','audiobook','papierowa') NOT NULL,
  `okladka` enum('twarda','miękka') DEFAULT NULL,
  `zdjecie` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `ksiazki`
--

INSERT INTO `ksiazki` (`id_produktu`, `tytul`, `seria`, `autor`, `wydawnictwo`, `jezyk_wydania`, `jezyk_oryginalu`, `liczba_stron`, `numer_wydania`, `data_premiery`, `rok_wydania`, `forma`, `okladka`, `zdjecie`) VALUES
(1, 'Harry Potter i Kamień Filozoficzny', 'Harry Potter', 'J.K. Rowling', 'Media Rodzina', 'polski', 'angielski', 320, 1, '2000-04-10', 2000, 'papierowa', 'twarda', 'hp1.jpg'),
(2, 'Harry Potter i Komnata Tajemnic', 'Harry Potter', 'J.K. Rowling', 'Media Rodzina', 'polski', 'angielski', 352, 1, '2001-10-10', 2001, 'papierowa', 'twarda', 'hp2.jpg'),
(3, 'Harry Potter i Więzień Azkabanu', 'Harry Potter', 'J.K. Rowling', 'Media Rodzina', 'polski', 'angielski', 400, 1, '2002-11-12', 2002, 'papierowa', 'twarda', 'hp3.jpg'),
(4, 'Władca Pierścieni: Drużyna Pierścienia', NULL, 'J.R.R. Tolkien', 'Zysk i S-ka', 'polski', 'angielski', 534, 1, '2002-11-15', 2002, 'papierowa', 'miękka', 'lotr1.jpg'),
(5, 'Władca Pierścieni: Dwie Wieże', NULL, 'J.R.R. Tolkien', 'Zysk i S-ka', 'polski', 'angielski', 420, 1, '2003-06-15', 2003, 'papierowa', 'miękka', 'lotr2.jpg'),
(6, 'Władca Pierścieni: Powrót Króla', NULL, 'J.R.R. Tolkien', 'Zysk i S-ka', 'polski', 'angielski', 620, 1, '2004-07-20', 2004, 'papierowa', 'miękka', 'lotr3.jpg'),
(7, 'Cień wiatru', 'Cmentarz Zapomnianych Książek', 'Carlos Ruiz Zafón', 'Muza', 'polski', 'hiszpański', 500, 1, '2005-10-10', 2005, 'papierowa', 'twarda', 'cien_wiatru.jpg'),
(8, 'Gra Anioła', 'Cmentarz Zapomnianych Książek', 'Carlos Ruiz Zafón', 'Muza', 'polski', 'hiszpański', 650, 1, '2008-05-10', 2008, 'papierowa', 'twarda', 'gra_aniola.jpg'),
(9, 'Więzień nieba', 'Cmentarz Zapomnianych Książek', 'Carlos Ruiz Zafón', 'Muza', 'polski', 'hiszpański', 400, 1, '2012-06-15', 2012, 'papierowa', 'twarda', 'wiezien_nieba.jpg'),
(10, 'Hobbit, czyli tam i z powrotem', NULL, 'J.R.R. Tolkien', 'Prószyński i S-ka', 'polski', 'angielski', 310, 3, '2000-12-01', 1996, 'ebook', NULL, 'hobbit.jpg'),
(11, 'Sapiens: Od zwierząt do bogów', NULL, 'Yuval Noah Harari', 'Wydawnictwo Literackie', 'polski', 'hebrajski', 512, 1, '2017-09-18', 2017, 'papierowa', 'miękka', 'sapiens.jpg'),
(12, 'Homo Deus: Krótka historia jutra', NULL, 'Yuval Noah Harari', 'Wydawnictwo Literackie', 'polski', 'hebrajski', 450, 1, '2018-02-25', 2018, 'papierowa', 'miękka', 'homo_deus.jpg'),
(13, 'Becoming', NULL, 'Michelle Obama', 'Agora', 'polski', 'angielski', 448, 1, '2018-11-13', 2018, 'audiobook', NULL, 'becoming.jpg'),
(14, 'Becoming', NULL, 'Michelle Obama', 'Agora', 'polski', 'angielski', 448, 1, '2018-11-13', 2018, 'papierowa', 'twarda', 'becoming.jpg'),
(15, 'Małe życie', NULL, 'Hanya Yanagihara', 'W.A.B.', 'polski', 'angielski', 816, 1, '2015-03-10', 2015, 'papierowa', 'twarda', 'male_zycie.jpg'),
(16, 'Inferno', NULL, 'Dan Brown', 'Albatros', 'polski', 'angielski', 624, 1, '2013-05-14', 2013, 'papierowa', 'miękka', 'inferno.jpg'),
(17, 'Kod Leonarda da Vinci', 'Robert Langdon', 'Dan Brown', 'Albatros', 'polski', 'angielski', 568, 1, '2003-05-01', 2003, 'papierowa', 'miękka', 'kod_leonarda.jpg'),
(18, 'Anioły i Demony', 'Robert Langdon', 'Dan Brown', 'Albatros', 'polski', 'angielski', 576, 1, '2001-08-28', 2001, 'papierowa', 'miękka', 'anioly_i_demony.jpg'),
(19, 'Zaginiony symbol', 'Robert Langdon', 'Dan Brown', 'Albatros', 'polski', 'angielski', 640, 1, '2009-09-15', 2009, 'ebook', NULL, 'zaginiony_symbol.jpg'),
(20, 'Harry Potter i Kamień Filozoficzny', 'Harry Potter', 'J.K. Rowling', 'Media Rodzina', 'polski', 'angielski', 320, 2, '2000-04-10', 2000, 'audiobook', NULL, 'hp1.jpg'),
(21, 'Harry Potter i Komnata Tajemnic', 'Harry Potter', 'J.K. Rowling', 'Media Rodzina', 'polski', 'angielski', 352, 2, '2001-10-10', 2001, 'ebook', NULL, 'hp2.jpg'),
(22, 'Metro 2033', NULL, 'Dmitry Glukhovsky', 'Insignis', 'polski', 'rosyjski', 600, 1, '2010-01-15', 2010, 'papierowa', 'twarda', 'metro2033.jpg'),
(23, 'Metro 2034', NULL, 'Dmitry Glukhovsky', 'Insignis', 'polski', 'rosyjski', 450, 1, '2011-05-20', 2011, 'papierowa', 'twarda', 'metro2034.jpg'),
(24, 'Metro 2035', NULL, 'Dmitry Glukhovsky', 'Insignis', 'polski', 'rosyjski', 500, 1, '2015-09-23', 2015, 'papierowa', 'twarda', 'metro2035.jpg'),
(25, 'Człowiek o 24 twarzach', NULL, 'Daniel Keyes', 'Świat Książki', 'polski', 'angielski', 368, 1, '1981-03-20', 1981, 'papierowa', 'miękka', '24_twarze.jpg'),
(26, 'Harry Potter i Więzień Azkabanu', 'Harry Potter', 'J.K. Rowling', 'Media Rodzina', 'polski', 'angielski', 400, 2, '2002-11-12', 2002, 'audiobook', NULL, 'hp3.jpg'),
(27, 'Duma i uprzedzenie', NULL, 'Jane Austen', 'Znak', 'polski', 'angielski', 350, 1, '1813-01-28', 1813, 'papierowa', 'miękka', 'duma_i_uprzedzenie.jpg'),
(28, 'Emma', NULL, 'Jane Austen', 'Znak', 'polski', 'angielski', 500, 1, '1815-12-23', 1815, 'papierowa', 'miękka', 'emma.jpg'),
(29, 'Jane Eyre', NULL, 'Charlotte Brontë', 'MG', 'polski', 'angielski', 480, 1, '1847-10-16', 1847, 'papierowa', 'miękka', 'jane_eyre.jpg'),
(30, 'Wielki Gatsby', NULL, 'F. Scott Fitzgerald', 'Zysk i S-ka', 'polski', 'angielski', 300, 1, '1925-04-10', 1925, 'papierowa', 'twarda', 'gatsby.jpg');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `oceny_ksiazek`
--

CREATE TABLE `oceny_ksiazek` (
  `id_oceny` int(11) NOT NULL,
  `id_uzytkownika` int(11) DEFAULT NULL,
  `id_produktu` int(11) DEFAULT NULL,
  `ocena` int(11) DEFAULT NULL CHECK (`ocena` between 1 and 10),
  `komentarz` text DEFAULT NULL,
  `data_oceny` date DEFAULT curdate()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `oceny_ksiazek`
--

INSERT INTO `oceny_ksiazek` (`id_oceny`, `id_uzytkownika`, `id_produktu`, `ocena`, `komentarz`, `data_oceny`) VALUES
(1, 101, 1, 4, 'Świetna książka, pełna magii i przygód!', '2024-11-30'),
(2, 102, 5, 5, 'Klasyka fantasy, warto przeczytać.', '2024-12-01'),
(3, 103, 10, 5, 'Zachwycająca historia, zdecydowanie polecam.', '2024-12-02'),
(4, 104, 7, 4, 'Dobra książka, ale momentami przydługawa.', '2024-11-28'),
(5, 105, 3, 5, 'Nie do końca mój klimat, ale dobrze napisana.', '2024-12-03'),
(6, 101, 10, 4, 'Świetny audiobook, wciągająca narracja.', '2024-11-29'),
(7, 102, 15, 4, 'Poruszająca historia, warto przeczytać.', '2024-12-01'),
(8, 103, 20, 5, 'Książka mojego dzieciństwa, zawsze wracam do niej z sentymentem.', '2024-12-02'),
(9, 104, 16, 3, 'Ciekawa, ale miejscami przewidywalna.', '2024-11-28'),
(10, 105, 22, 2, 'Mroczna, ale nie dla każdego.', '2024-12-03');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `uzytkownicy`
--

CREATE TABLE `uzytkownicy` (
  `id_uzytkownika` int(11) NOT NULL,
  `imie` varchar(50) NOT NULL,
  `nazwisko` varchar(50) NOT NULL,
  `email` varchar(100) NOT NULL,
  `haslo` varchar(255) NOT NULL,
  `data_urodzenia` date NOT NULL,
  `data_rejestracji` date DEFAULT curdate(),
  `status` enum('aktywny','zawieszony','zablokowany') DEFAULT 'aktywny'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `uzytkownicy`
--

INSERT INTO `uzytkownicy` (`id_uzytkownika`, `imie`, `nazwisko`, `email`, `haslo`, `data_urodzenia`, `data_rejestracji`, `status`) VALUES
(7, 'Kamil', 'Drożdż', '123dz123@gmail.com', '$2y$10$Cc3Rw.OMcPL8kmzqVd0DH.mEo0Hu7oH8QNaBlUTtBLKOo0WDCe72G', '2002-05-06', '2024-12-04', 'aktywny'),
(8, 'Kamil', 'Drożdż', 'kamildrozdz123@gmail.com', '$2y$10$leVUWjrx3Gm9NhtqH/hDR.QWBhfHRr2tkjqofnYcfo43DMr3AhfGu', '2002-05-06', '2024-12-04', 'aktywny'),
(101, 'Jan', 'Kowalski', 'jan.kowalski@example.com', '1a7fcdd5a9fd433523268883cfded9d0', '1990-05-15', '2024-11-30', 'aktywny'),
(102, 'Anna', 'Nowak', 'anna.nowak@example.com', 'dba24ab5cf9260f8125612ffbf97f82f', '1985-03-20', '2024-11-28', 'aktywny'),
(103, 'Piotr', 'Wiśniewski', 'piotr.wisniewski@example.com', 'a2fed48cdbf36d3a13236e9efb84152c', '1992-12-10', '2024-11-29', 'aktywny'),
(104, 'Katarzyna', 'Zielińska', 'katarzyna.zielinska@example.com', 'ec1e354d0c5c7ecfeb61c7f3dabf528d', '1995-07-08', '2024-12-01', 'aktywny'),
(105, 'Marek', 'Dąbrowski', 'marek.dabrowski@example.com', '684d97f00b568bd720ba945df3161b11', '1988-09-25', '2024-11-27', 'zawieszony');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `wypozyczenia`
--

CREATE TABLE `wypozyczenia` (
  `id_wypozyczenia` int(11) NOT NULL,
  `id_uzytkownika` int(11) DEFAULT NULL,
  `id_produktu` int(11) DEFAULT NULL,
  `data_wypozyczenia` date DEFAULT curdate(),
  `data_zwrotu` date DEFAULT NULL,
  `status` enum('wypożyczona','zwrócona','przetrzymana') DEFAULT 'wypożyczona'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Dumping data for table `wypozyczenia`
--

INSERT INTO `wypozyczenia` (`id_wypozyczenia`, `id_uzytkownika`, `id_produktu`, `data_wypozyczenia`, `data_zwrotu`, `status`) VALUES
(1, 101, 1, '2024-12-01', '2024-12-15', 'wypożyczona'),
(2, 102, 5, '2024-11-20', '2024-12-04', 'zwrócona'),
(3, 103, 10, '2024-11-28', NULL, 'przetrzymana'),
(4, 104, 7, '2024-12-02', '2024-12-16', 'wypożyczona'),
(5, 105, 3, '2024-11-25', '2024-12-03', 'zwrócona');

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `ksiazki`
--
ALTER TABLE `ksiazki`
  ADD PRIMARY KEY (`id_produktu`);

--
-- Indeksy dla tabeli `oceny_ksiazek`
--
ALTER TABLE `oceny_ksiazek`
  ADD PRIMARY KEY (`id_oceny`),
  ADD KEY `id_uzytkownika` (`id_uzytkownika`),
  ADD KEY `id_produktu` (`id_produktu`);

--
-- Indeksy dla tabeli `uzytkownicy`
--
ALTER TABLE `uzytkownicy`
  ADD PRIMARY KEY (`id_uzytkownika`),
  ADD UNIQUE KEY `email` (`email`);

--
-- Indeksy dla tabeli `wypozyczenia`
--
ALTER TABLE `wypozyczenia`
  ADD PRIMARY KEY (`id_wypozyczenia`),
  ADD KEY `id_uzytkownika` (`id_uzytkownika`),
  ADD KEY `id_produktu` (`id_produktu`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `ksiazki`
--
ALTER TABLE `ksiazki`
  MODIFY `id_produktu` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=31;

--
-- AUTO_INCREMENT for table `oceny_ksiazek`
--
ALTER TABLE `oceny_ksiazek`
  MODIFY `id_oceny` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT for table `uzytkownicy`
--
ALTER TABLE `uzytkownicy`
  MODIFY `id_uzytkownika` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=106;

--
-- AUTO_INCREMENT for table `wypozyczenia`
--
ALTER TABLE `wypozyczenia`
  MODIFY `id_wypozyczenia` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `oceny_ksiazek`
--
ALTER TABLE `oceny_ksiazek`
  ADD CONSTRAINT `oceny_ksiazek_ibfk_1` FOREIGN KEY (`id_uzytkownika`) REFERENCES `uzytkownicy` (`id_uzytkownika`),
  ADD CONSTRAINT `oceny_ksiazek_ibfk_2` FOREIGN KEY (`id_produktu`) REFERENCES `ksiazki` (`id_produktu`);

--
-- Constraints for table `wypozyczenia`
--
ALTER TABLE `wypozyczenia`
  ADD CONSTRAINT `wypozyczenia_ibfk_1` FOREIGN KEY (`id_uzytkownika`) REFERENCES `uzytkownicy` (`id_uzytkownika`),
  ADD CONSTRAINT `wypozyczenia_ibfk_2` FOREIGN KEY (`id_produktu`) REFERENCES `ksiazki` (`id_produktu`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
