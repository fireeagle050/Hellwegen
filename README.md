# Hellwegen

## Spis Treści
1. [Wizja Gry](#wizja-gry)
2. [Główne Założenia](#główne-założenia)
3. [Setting: Europa XIV Wieku](#setting-europa-xiv-wieku)
4. [Kluczowe Elementy Rozgrywki](#kluczowe-elementy-rozgrywki)
    - [Interfejs Użytkownika](#interfejs-użytkownika)
    - [Rozwój Postaci](#rozwój-postaci)
    - [System Ekonomiczny](#system-ekonomiczny)
    - [Ekwipunek i Przedmioty](#ekwipunek-i-przedmioty)
    - [System Wydarzeń Losowych](#system-wydarzeń-losowych)
    - [Walka i Podboje](#walka-i-podboje)
    - [Interakcje i Fabuła](#interakcje-i-fabuła)
5. [Struktura Techniczna](#struktura-techniczna)
    - [Język i Technologie](#język-i-technologie)
    - [Struktura Projektu](#struktura-projektu)
6. [Plan Rozwoju (Roadmap)](#plan-rozwoju-roadmap)

---

## Wizja Gry
**Hellwegen** to historyczna gra strategiczno-fabularna (RPG) 2D, osadzona w realiach XIV-wiecznej Europy. Gracz wciela się w postać, której celem jest przetrwanie i zbudowanie swojego dziedzictwa w burzliwym świecie pełnym wojen, chorób i intryg. Rozgrywka kładzie silny nacisk na aspekty **matematyczne, ekonomiczne i historyczne**, wymagając od gracza logicznego myślenia, planowania i adaptacji do dynamicznie zmieniających się warunków.

Gra została zaprojektowana z myślą o **skalowalności i wydajności**, co pozwoli na jej przyszłą rozbudowę o nowe okresy historyczne, mechaniki i zawartość bez konieczności ingerencji w rdzeń silnika gry.

## Główne Założenia
*   **Realizm historyczny**: Wydarzenia, postacie, przedmioty, technologie i struktury społeczne są oparte na faktach historycznych z XIV wieku.
*   **Głębia ekonomiczna**: Dynamiczny rynek z wahającymi się cenami, różnorodne źródła dochodu i złożone zależności ekonomiczne.
*   **Nieliniowa fabuła**: Decyzje gracza mają realny wpływ na losy postaci i otaczającego ją świata.
*   **Rozgrywka oparta na danych**: Kluczowe elementy gry (wydarzenia, przedmioty, NPC) są definiowane w zewnętrznych plikach JSON, co ułatwia modyfikację i rozbudowę.
*   **Wydajność**: Prosta, czytelna grafika 2D i zoptymalizowana logika gry zapewniają płynne działanie nawet na słabszych konfiguracjach sprzętowych.

## Setting: Europa XIV Wieku
Wybrany okres to czas wielkich przemian i kontrastów – idealne tło dla fascynującej fabuły. To epoka, w której miały miejsce:
*   **Czarna Śmierć**: Epidemia dżumy, która zdziesiątkowała populację Europy, tworząc próżnię społeczną i ekonomiczną.
*   **Wojna Stuletnia**: Konflikt między Anglią a Francją, oferujący możliwości kariery wojskowej.
*   **Rozkwit Hanzy**: Potężny związek miast handlowych, stwarzający szansę na bogactwo poprzez handel.
*   **Schizma zachodnia**: Kryzys w Kościele katolickim, wpływający na politykę i wiarę.
*   **Zmierzch rycerstwa**: Ciężka jazda powoli traci na znaczeniu na rzecz piechoty i wczesnej broni palnej.

## Kluczowe Elementy Rozgrywki

### Interfejs Użytkownika
Interfejs jest zaprojektowany z myślą o przejrzystości i dostarczaniu kluczowych informacji w skondensowanej formie.

*   **Panel Główny (widoczny stale):**
    *   **Karta Wydarzenia**: Centralny punkt interfejsu, gdzie pojawiają się opisy sytuacji, dialogi i opcje wyboru. Tło karty będzie dynamicznie zmieniać się w zależności od lokacji i kontekstu.
    *   **Panel Zmiennych Globalnych**: Wyświetla kluczowe informacje: data (dzień, miesiąc, rok, pora roku), stan skarbca, aktualna pogoda, temperatura, status i prestiż postaci.
*   **Okna Dostępne na Żądanie:**
    *   **Ekran Postaci**:
        *   **Wykres Statystyk**: Graficzna reprezentacja kluczowych atrybutów postaci, zmieniająca się w czasie rzeczywistym.
        *   **Wygląd i Ekwipunek**: Wizualizacja postaci oraz sloty na poszczególne części ubioru i uzbrojenia.
    *   **Mapa Świata**: Widok strategiczny z miastami, szlakami handlowymi i lokacjami specjalnymi. Umożliwia planowanie podróży, zarządzanie armią i ekspansję terytorialną.
    *   **Dziennik (Journal)**: Zapis ważnych wydarzeń, zadań i posiadanych informacji.

### Rozwój Postaci
Postać jest opisana przez zestaw stałych i zmiennych atrybutów, które gracz rozwija w toku rozgrywki.

*   **Atrybuty Główne (rozwijane przez doświadczenie):**
    *   **Siła (STR)**: Walka wręcz, udźwig, praca fizyczna.
    *   **Zręczność (AGI)**: Uniki, szybkość ataku, umiejętności rzemieślnicze.
    *   **Spostrzegawczość (PER)**: Zasięg widzenia na mapie, szansa na wykrycie pułapek i zasadzek.
    *   **Wytrzymałość (END)**: Punkty życia, odporność na choroby i głód.
    *   **Charyzma (CHA)**: Negocjacje, zdolności przywódcze, wpływ na morale.
    *   **Inteligencja (INT)**: Szybkość nauki, planowanie strategiczne, rozwiązywanie zagadek.
    *   **Wiara (FAI)**: Odporność na kryzysy moralne, relacje z instytucjami religijnymi.
    *   **Szczęście (LCK)**: Modyfikator losowych wydarzeń.

*   **Zmienne Postaci (zmieniające się dynamicznie):**
    *   **Wiek**: Wpływa na statystyki i cykl życia.
    *   **Punkty Życia (HP)**: Aktualny stan zdrowia.
    *   **Doświadczenie (XP)**: Gromadzone w celu rozwoju atrybutów.
    *   **Prestiż/Szacunek**: Status społeczny, wpływa na interakcje z NPC.
    *   **Pieniądze**: Waluta używana w grze.
    *   **Samopoczucie**: Wpływa na efektywność działań postaci.

### System Ekonomiczny
Gospodarka jest kluczowym elementem gry.
*   **Dochody**: Możliwe do uzyskania poprzez pracę, najemnictwo, handel, rzemiosło, hazard, a także kradzież czy rozbój.
*   **Dynamiczny Rynek**: Ceny towarów różnią się w zależności od regionu, pory roku i wydarzeń losowych (np. wojna podnosi cenę zboża i żelaza).
*   **Inwestycje**: Możliwość zakupu nieruchomości (dom, warsztat, zamek) lub inwestowania w karawany handlowe.

### Ekwipunek i Przedmioty
Przedmioty są zgodne z realiami historycznymi XIV wieku.

*   **Broń Biała**: Miecze (krótkie, długie, dwuręczne), topory, maczugi, włócznie, sztylety.
*   **Broń Dystansowa**: Łuki (krótkie, długie), kusze, proce.
*   **Opancerzenie**: Przeszywanice, kolczugi, hełmy (garnczkowe, przyłbice), elementy pancerza płytowego (napierśniki, naręczaki).
*   **Transport**: Koń, wóz, łódź rzeczna.
*   **Narzędzia i Towary**: Narzędzia rzemieślnicze, żywność, surowce, towary luksusowe.
*   **Broń Oblężnicza**: Tarany, drabiny, wczesna artyleria prochowa (np. bombardy).

### System Wydarzeń Losowych
Wydarzenia te dodają grze nieprzewidywalności i głębi.

*   **Klimatyczne**: Susze, powodzie, ostre zimy, zaćmienia słońca.
*   **Sytuacyjne**: Napaść bandytów, pożar w mieście, spotkanie wędrownego kupca, propozycja misji.
*   **Życiowe**: Narodziny dziecka, ślub, choroba, śmierć członka rodziny.

### Walka i Podboje
*   **System turowy**: Walka odbywa się w turach na uproszczonej siatce taktycznej.
*   **Statystyki w walce**: Wynik starcia zależy od atrybutów postaci, jej ekwipunku, morale oraz czynników losowych.
*   **Oblężenia**: Zdobywanie i obrona warownych lokacji wymaga odpowiedniego przygotowania i sprzętu.

### Interakcje i Fabuła
*   **Dialogi z wyborami**: Rozmowy z postaciami niezależnymi (NPC) oferują wybory, które kształtują relacje i otwierają nowe ścieżki fabularne.
*   **System reputacji**: Działania gracza wpływają na to, jak postrzegają go różne frakcje (szlachta, duchowieństwo, mieszczanie, chłopi).

## Struktura Techniczna

### Język i Technologie
*   **Język programowania**: **C++** - dla maksymalnej wydajności, kontroli nad pamięcią i możliwości przyszłej integracji z silnikami lub portowania na różne platformy (w tym Steam, Sklep Play).
*   **Kompilacja**: **CMake** - jako standardowy, wieloplatformowy system budowania projektu.
*   **Grafika**: Lekka biblioteka 2D, np. **SFML** lub **Raylib**, aby oddzielić logikę gry od warstwy prezentacji.
*   **Format danych**: **JSON** - dla przechowywania danych o wydarzeniach, przedmiotach, postaciach i konfiguracji gry. Jest czytelny dla człowieka i łatwy do parsowania.

### Struktura Projektu
Projekt będzie zorganizowany w standardowej, przejrzystej strukturze katalogów:
```
/Hellwegen
|
├── /assets/         # Pliki graficzne (PNG, JPG), czcionki, dźwięki
├── /build/          # Pliki generowane przez CMake (ignorowane przez Git)
├── /data/           # Pliki JSON z danymi gry (przedmioty, wydarzenia, etc.)
├── /docs/           # Dokumentacja projektu
├── /include/        # Pliki nagłówkowe C++ (.h, .hpp)
├── /lib/            # Zewnętrzne biblioteki (np. SFML, Raylib)
├── /src/            # Pliki źródłowe C++ (.cpp)
|   ├── /core/       # Rdzeń silnika gry (pętle, zarządzanie stanem)
|   ├── /game/       # Logika rozgrywki (postać, ekonomia, walka)
|   └── /graphics/   # Obsługa grafiki i interfejsu
|
├── CMakeLists.txt   # Główny plik konfiguracyjny CMake
└── README.md        # Ten plik
```

## Plan Rozwoju (Roadmap)
Projekt będzie rozwijany w następujących fazach:

*   **Faza 1: Fundamenty (Proof of Concept)**
    *   Stworzenie szkieletu projektu (struktura folderów, CMake).
    *   Implementacja rdzenia silnika gry (główna pętla, zarządzanie oknem).
    *   Stworzenie i wyświetlenie podstawowego interfejsu.
    *   Mechanizm tworzenia postaci i podstawowe statystyki.

*   **Faza 2: Implementacja Kluczowych Mechanik**
    *   Wczytywanie danych z plików JSON.
    *   Implementacja systemu wydarzeń i dialogów.
    *   Stworzenie systemu ekonomicznego (rynek, dochody).
    *   Zaprojektowanie i wdrożenie systemu ekwipunku.

*   **Faza 3: Rozbudowa i Treść**
    *   Implementacja mechaniki walki turowej.
    *   Stworzenie mapy świata i mechaniki podróży.
    *   Dodanie dużej liczby wydarzeń, przedmiotów i postaci.
    *   Wprowadzenie systemu zapisu i odczytu stanu gry.

*   **Faza 4: Balans, Optymalizacja i Wydanie**
    *   Balansowanie rozgrywki.
    *   Optymalizacja wydajności.
    *   Testy i poprawki błędów.
    *   Przygotowanie do dystrybucji.
```