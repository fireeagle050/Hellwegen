# Hellwegen

*Gra o życiu, walce i przeznaczeniu w mrocznym, średniowiecznym świecie.*

---

## Spis Treści
1. [Wizja Gry](#1-wizja-gry)
2. [Główne Cechy](#2-główne-cechy)
3. [Technologie](#3-technologie)
4. [Podstawy Mechaniki Gry](#4-podstawy-mechaniki-gry)
    - [4.1. Czas i Świat Gry](#41-czas-i-świat-gry)
    - [4.2. Postać Gracza](#42-postać-gracza)
    - [4.3. Statystyki i Umiejętności](#43-statystyki-i-umiejętności)
    - [4.4. Ekwipunek](#44-ekwipunek)
    - [4.5. System Losowych Zdarzeń](#45-system-losowych-zdarzeń)
5. [Rozgrywka](#5-rozgrywka)
    - [5.1. Interakcje i Fabuła](#51-interakcje-i-fabuła)
    - [5.2. Walka i Podboje](#52-walka-i-podboje)
    - [5.3. Rozwój Postaci i Zdobywanie Dochodów](#53-rozwój-postaci-i-zdobywanie-dochodów)
    - [5.4. Otoczenie i Wsparcie](#54-otoczenie-i-wsparcie)
6. [Architektura Techniczna](#6-architektura-techniczna)
    - [6.1. System Zmiennych](#61-system-zmiennych)
    - [6.2. Skalowalność i Modowalność](#62-skalowalność-i-modowalność)
    - [6.3. Wydajność](#63-wydajność)
7. [Plan Rozwoju (Roadmap)](#7-plan-rozwoju-roadmap)

---

## 1. Wizja Gry

**Hellwegen** to gra RPG 2D z otwartym światem, która kładzie nacisk na symulację życia i podejmowanie znaczących decyzji. Gracz wciela się w postać w surowym, inspirowanym średniowieczem świecie, prowadząc ją od narodzin aż po starość lub chwalebną (bądź nie) śmierć. Kluczem do sukcesu jest mądre zarządzanie statystykami, gromadzenie majątku, budowanie relacji oraz przetrwanie w świecie pełnym niebezpieczeństw i nieoczekiwanych zdarzeń. Gra została zaprojektowana z myślą o logice, skalowalności i wydajności, aby zapewnić płynną i rozbudowaną rozgrywkę.

## 2. Główne Cechy

- **Głęboki rozwój postaci:** Prowadź postać przez całe życie, od narodzin po śmierć, kształtując jej losy.
- **Dynamiczny świat:** Świat gry reaguje na działania gracza, a losowe wydarzenia (klimatyczne, społeczne, osobiste) sprawiają, że żadna rozgrywka nie jest taka sama.
- **System reputacji:** Zdobywaj szacunek lub siej postrach, co wpłynie na interakcje z postaciami niezależnymi (NPC).
- **Nieliniowa fabuła:** Decyzje w dialogach i kluczowe wybory moralne mają realny wpływ na bieg historii.
- **Zarządzanie zasobami:** Gromadź majątek, zarządzaj ekwipunkiem, inwestuj w nieruchomości i buduj swoją potęgę.
- **Taktyczna walka turowa:** Planuj swoje ruchy w starciach, wykorzystując statystyki, umiejętności i ekwipunek.
- **Skalowalność:** Prosta w rozbudowie struktura gry pozwala na łatwe dodawanie nowych przedmiotów, postaci, wydarzeń i lokacji.

## 3. Technologie

- **Grafika:** Zasoby graficzne w formatach `PNG` (dla sprite'ów), `SVG` (dla interfejsu) oraz `JPG` (dla teł i portretów).
- **Animacje:** Proste animacje klatkowe (sprite sheets) w celu zapewnienia maksymalnej wydajności.
- **Logika gry:** Elastyczny silnik gry, który może być zaimplementowany w `JavaScript` (web), `Python` (prototypowanie, narzędzia) lub `C++` (wysoka wydajność).
- **Dane gry:** Konfiguracja przedmiotów, postaci, wydarzeń, dialogów i lokacji przechowywana w plikach `JSON` lub `CSV`, co ułatwia modyfikację i rozbudowę.

## 4. Podstawy Mechaniki Gry

### 4.1. Czas i Świat Gry

- **Czas:** System oparty na dniach, miesiącach i latach. Czas płynie w turach (np. 1 tura = 1 dzień). Pory roku wpływają na dostępność zasobów, pogodę i wydarzenia.
- **Narodziny:** Postać jest generowana z określonymi cechami bazowymi:
    - **Płeć:** Mężczyzna / Kobieta.
    - **Imię:** Wybierane przez gracza lub losowane.
    - **Rodzice:** Matka i ojciec (NPC), których status społeczny i geny wpływają na startowe statystyki postaci.
    - **Miejsce i data urodzenia:** Wpływa na początkowe warunki i dostępne możliwości.

### 4.2. Postać Gracza

Zestaw dynamicznych atrybutów opisujących stan postaci.

- **Wiek:** `integer` - Wpływa na statystyki fizyczne i możliwości (np. dziecko nie może walczyć, starzec ma mniej siły).
- **Punkty Życia (HP):** `integer` - Aktualny stan zdrowia. Spadek do 0 oznacza śmierć.
- **Doświadczenie (XP):** `integer` - Zdobywane za wykonywanie zadań, wygrane walki, etc. Prowadzi do awansu na kolejne poziomy.
- **Aura / Zauroczenie:** `integer` - Mistyczna cecha wpływająca na losowe wydarzenia, relacje z NPC i reakcje zwierząt.
- **Sylwetka / Wygląd:** `string` / `obiekty statystyczne` - Opis wyglądu, który może ulegać zmianie (np. blizny po walce, zmiana wagi).
- **Szacunek:** `integer` - Reputacja w danej społeczności. Wysoki szacunek otwiera nowe opcje dialogowe i handlowe.
- **Pieniądze (Grosze):** `integer` - Główna waluta w grze.
- **Status społeczny:** `string` - np. "Chłop", "Mieszczanin", "Rycerz", "Lord". Wpływa na dochody, interakcje i styl życia.
- **Wyznanie:** `string` - Przynależność do frakcji religijnej (np. Panteon Starych Bogów, Kult Jedynego Słońca, Ścieżka Przodków). Wpływa na morale i relacje.
- **Ceny towarów:** `dynamiczne` - Ceny zależą od lokacji, pory roku i globalnych wydarzeń (np. wojna podnosi cenę żelaza).
- **Samopoczucie:** `integer` - Stan psychiczny postaci (-100 do 100). Wpływa na efektywność w walce, pracy i dialogach.

### 4.3. Statystyki i Umiejętności

Podstawowe atrybuty postaci, rozwijane wraz z doświadczeniem.

- **Siła (STR):** Wpływa na obrażenia w walce wręcz, udźwig ekwipunku oraz wymagania do używania ciężkiej broni.
- **Zwinność (AGI):** Decyduje o szansie na unik, skuteczności kradzieży, inicjatywie w walce i zręcznych akcjach.
- **Postrzeganie (PER):** Zwiększa szansę na wykrycie pułapek, ukrytych przedmiotów, zasadzek oraz dostrzeganie słabych punktów wroga.
- **Wytrzymałość (END):** Określa maksymalną liczbę punktów życia (HP), odporność na choroby, trucizny i zmęczenie.
- **Charyzma (CHA):** Kluczowa dla negocjacji, perswazji, dowodzenia armią i budowania relacji z NPC.
- **Inteligencja (INT):** Wpływa na szybkość zdobywania doświadczenia, rozwiązywanie zagadek, planowanie strategiczne i opcje dialogowe.
- **Szczęście (LCK):** Modyfikuje wyniki losowych zdarzeń, szansę na znalezienie cennego łupu i krytyczne trafienia w walce.
- **Wiara (FAI):** Wpływa na relacje z frakcjami religijnymi, morale armii i dostęp do specjalnych umiejętności lub wsparcia.

### 4.4. Ekwipunek

| Kategoria | Typ | Przykłady |
|---|---|---|
| **Broń** | Biała | Miecze, topory, noże, maczugi, włócznie, kopie |
| | Dalekiego zasięgu | Łuki, kusze, proce, oszczepy, kamienie |
| | Oblężnicza | Balista, katapulta, taran, działo, dynamit |
| **Pancerz i Obrona**| Pancerz | Napierśnik, hełm, rękawice, spodnie, buty (skórzane, kolcze, płytowe) |
| | Tarcze | Drewniana, wzmacniana, pawęż |
| **Transport** | Osobisty | Koń, osioł |
| | Towarowy | Wóz, powóz |
| | Wodny | Łódka, statek |
| **Ekwipunek Osobisty** | Pojemniki | Sakwa, plecak, juki |
| | Narzędzia | Liny, wytrychy, narzędzia rzemieślnicze |

### 4.5. System Losowych Zdarzeń

Zdarzenia modyfikują świat i postać, dodając element nieprzewidywalności.

- **Klimatyczne:** Susza, powódź, ostra zima, zaćmienie słońca, deszcz meteorów.
- **Sytuacyjne:** Napaść bandytów, zasadzka, spotkanie wędrownego kupca, propozycja pracy, kradzież.
- **Życiowe:** Narodziny dziecka, ślub, choroba, śmierć członka rodziny, dziedziczenie spadku.

## 5. Rozgrywka

### 5.1. Interakcje i Fabuła

- **Dialogi:** System oparty na wyborach, gdzie posiadane statystyki (np. `CHA`, `INT`) oraz przedmioty mogą odblokować dodatkowe opcje.
- **Zadania (Questy):** Zlecane przez NPC, mogą być nieliniowe i prowadzić do różnych zakończeń.
- **Relacje:** Postać może budować przyjaźnie, wrogość, a nawet zakładać rodzinę.

### 5.2. Walka i Podboje

- **System turowy:** Walka odbywa się w turach, gdzie inicjatywa zależy od statystyki `AGI`.
- **Mechanika:** Sukces akcji (atak, unik, parada) jest obliczany na podstawie statystyk postaci, ekwipunku oraz modyfikatora losowego. Przykładowa formuła obrażeń: `(Obrażenia = (Siła Postaci + Obrażenia Broni) * Modyfikator Losowy - Pancerz Przeciwnika)`.
- **Skala:** Od pojedynków jeden na jednego, po potyczki drużyn i bitwy armii.

### 5.3. Rozwój Postaci i Zdobywanie Dochodów

Postać może zarabiać na życie na wiele sposobów, co wpływa na jej status i dostępne możliwości.

- **Legalne ścieżki:** Praca jako najemnik, rzemieślnik, kupiec, rolnik.
- **Nielegalne ścieżki:** Kradzież kieszonkowa, włamania, napady na podróżnych, hazard.
- **Inne:** Wygrane w turniejach, zarządzanie lennami, poszukiwanie skarbów.

### 5.4. Otoczenie i Wsparcie

| Typ Mieszkania | Korzyści | Wymagania (przykładowe) |
|---|---|---|
| Zamek | Prestiż, obrona, dochód | Tytuł szlachecki, ogromne fundusze |
| Willa / Dom | Bezpieczeństwo, komfort | Status mieszczanina, znaczne fundusze |
| Chata / Namiot | Niski koszt utrzymania | Brak |

- **Wsparcie:** Gracz może rekrutować lub zaprzyjaźniać się z NPC, którzy zapewniają wsparcie.
    - **Rodzina:** Małżonek, dzieci.
    - **Towarzysze:** Przyjaciele, kochankowie, członkowie drużyny.
    - **Zbrojni:** Najemnicy, armia, sojusznicy.

## 6. Architektura Techniczna

### 6.1. System Zmiennych

Rdzeń gry opiera się na systemie zmiennych. Wszystkie atrybuty postaci, relacje i stan świata są przechowywane jako liczby (`integer`) lub tekst (`string`). Decyzje i wydarzenia losowe to funkcje, które modyfikują te zmienne, tworząc dynamiczną i spójną logikę.

### 6.2. Skalowalność i Modowalność

Projekt jest tworzony z myślą o łatwej rozbudowie. Dzięki przechowywaniu danych w plikach `JSON/CSV`, dodawanie nowych elementów (np. miecz, zadanie, miasto) nie wymaga ingerencji w główny kod silnika gry. To otwiera drogę do tworzenia modyfikacji przez społeczność.

### 6.3. Wydajność

Priorytetem jest optymalizacja.
- **Grafika:** Prosta grafika 2D i oszczędne animacje klatkowe minimalizują obciążenie.
- **Logika:** Obliczenia są ograniczone do niezbędnego minimum na turę.
- **Determinizm:** Funkcje losowe są zaprojektowane tak, aby mogły być odtwarzalne (przy użyciu tego samego "ziarna" - seeda), co ułatwia testowanie i debugowanie.

## 7. Plan Rozwoju (Roadmap)

Projekt będzie rozwijany w następujących fazach:

- **Faza 1: Rdzeń Mechaniki (Proof of Concept)**
    - Implementacja systemu postaci (statystyki, atrybuty).
    - Stworzenie podstawowego systemu czasu i tur.
    - Działający system ekwipunku i pieniędzy.
    - Prosta walka turowa (1 na 1).
- **Faza 2: Rozbudowa Świata i Interakcji**
    - Stworzenie mapy świata z kilkoma lokacjami (miasto, wieś, las).
    - Implementacja systemu dialogów i prostych zadań.
    - Wprowadzenie systemu losowych zdarzeń.
- **Faza 3: Treść i Fabuła**
    - Dodanie głównego wątku fabularnego.
    - Wprowadzenie większej liczby postaci, przedmiotów i zadań pobocznych.
    - Rozbudowa systemu relacji (rodzina, przyjaciele).
- **Faza 4: Optymalizacja i Polerowanie**
    - Ulepszenie interfejsu użytkownika (UI/UX).
    - Balansowanie rozgrywki.
    - Testowanie i usuwanie błędów.
- **Faza 5: Funkcje Zaawansowane**
    - Zarządzanie lennami i armiami.
    - Wojny frakcji.
    - Wsparcie dla modyfikacji.