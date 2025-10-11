# Hellwegen

*Gra strategiczno-fabularna oparta na realiach historycznych, matematyce i ekonomii, budowana od podstaw dla maksymalnej wydajności i kontroli.*

---

## Spis Treści
1. [Wizja Gry](#1-wizja-gry)
    - [1.1. Koncepcja](#11-koncepcja)
    - [1.2. Okres Historyczny: XIV Wiek](#12-okres-historyczny-xiv-wiek)
    - [1.3. Filozofia Projektu](#13-filozofia-projektu)
2. [Interfejs Użytkownika (UI)](#2-interfejs-użytkownika-ui)
    - [2.1. Układ Głównego Ekranu](#21-układ-głównego-ekranu)
    - [2.2. Dodatkowe Okna i Panele](#22-dodatkowe-okna-i-panele)
3. [Architektura i Technologie](#3-architektura-i-technologie)
    - [3.1. Wybrane Technologie](#31-wybrane-technologie)
    - [3.2. Struktura Projektu (C++)](#32-struktura-projektu-c)
4. [Podstawy Mechaniki Gry](#4-podstawy-mechaniki-gry)
    - [4.1. Postać i Statystyki](#41-postać-i-statystyki)
    - [4.2. Ekwipunek i Zasoby](#42-ekwipunek-i-zasoby)
    - [4.3. System Losowych Zdarzeń](#43-system-losowych-zdarzeń)
5. [Plan Rozwoju (Roadmap)](#5-plan-rozwoju-roadmap)

---

## 1. Wizja Gry

### 1.1. Koncepcja
**Hellwegen** to zaawansowana gra 2D, która symuluje życie jednostki w burzliwych realiach średniowiecznej Europy. Projekt łączy w sobie elementy strategii, gry fabularnej (RPG) oraz symulacji ekonomicznej. Kluczem do sukcesu jest podejmowanie trafnych decyzji opartych na analizie danych, myśleniu strategicznym i adaptacji do dynamicznie zmieniającego się świata. Gra jest głęboko osadzona w **matematyce, ekonomii i nauce**, a jej celem jest dostarczenie graczowi intelektualnego wyzwania.

### 1.2. Okres Historyczny: XIV Wiek
Akcja gry osadzona jest w **XIV wieku (lata 1300-1399)**. To czas wojen, epidemii (Czarna Śmierć), kryzysów religijnych (schizma papieska) i wielkich zmian ekonomicznych (potęga Hanzy), co stanowi idealne tło dla dynamicznej i nieprzewidywalnej rozgrywki. Wszystkie elementy gry – ekwipunek, budowle, wydarzenia, technologie – będą wiernie odzwierciedlać realia historyczne tej epoki.

### 1.3. Filozofia Projektu
- **Niezależność od silnika:** Rdzeń gry (logika, mechaniki) jest budowany w czystym C++, bez zależności od dużych, komercyjnych silników. Zapewnia to pełną kontrolę nad kodem, maksymalną wydajność i możliwość adaptacji do dowolnej technologii renderującej w przyszłości.
- **Skalowalność:** Architektura oparta na danych (`JSON`) pozwoli na łatwe dodawanie nowych epok historycznych, wydarzeń, przedmiotów i mechanik bez modyfikacji głównego kodu.
- **Realizm i Edukacja:** Gra ma w subtelny sposób uczyć o historii, ekonomii i związkach przyczynowo-skutkowych.

## 2. Interfejs Użytkownika (UI)

Interfejs będzie renderowany z użyciem lekkiej biblioteki graficznej, co zapewni szybkość działania i prostotę implementacji.

### 2.1. Układ Głównego Ekranu
Główny widok gry będzie składał się z kilku stałych sekcji:

1.  **Sekcja Wydarzenia (Centralna):** Aktywna karta z bieżącym wydarzeniem, tłem graficznym i opcjami wyboru.
2.  **Sekcja Zmiennych Globalnych (Górny Pasek):** Data, finanse, kluczowe wskaźniki rynkowe, pogoda, status.
3.  **Sekcja Postaci (Lewa Kolumna):** Portret postaci, wizualizacja ekwipunku i dynamiczny wykres statystyk.
4.  **Sekcja Mapy Świata (Prawa Kolumna):** Zminiaturyzowana mapa z opcjami interakcji (podróż, przegląd terytoriów).

### 2.2. Dodatkowe Okna i Panele
Dodatkowe ekrany (ekwipunek, rynek, dziennik zadań, drzewko dynastii) będą otwierane jako osobne, renderowane okna lub nakładki.

## 3. Architektura i Technologie

### 3.1. Wybrane Technologie
- **Język programowania:** **C++**. Wybór podyktowany najwyższą wydajnością, pełną kontrolą nad pamięcią i zasobami oraz statusem standardu w tworzeniu wysokopoziomowych systemów gier.
- **Biblioteka graficzna (warstwa prezentacji):** **SFML (Simple and Fast Multimedia Library)** lub **Raylib**. Te lekkie biblioteki posłużą do renderowania grafiki 2D, obsługi okien i wejścia. Są idealne do prototypowania i budowy gry, której logika pozostaje niezależna od warstwy wizualnej.
- **System budowania:** **CMake**. Zapewni wieloplatformowość i ułatwi zarządzanie zależnościami.
- **Format danych:** **JSON**. Dane o przedmiotach, wydarzeniach i postaciach będą przechowywane w plikach `.json`, co zapewni modularność i łatwość edycji.

### 3.2. Struktura Projektu (C++)
Struktura folderów będzie zorganizowana w sposób typowy dla projektów C++ z oddzieleniem kodu źródłowego, plików nagłówkowych i zasobów.

```
hellwegen/
│
├── src/                      # Pliki źródłowe (.cpp)
│   ├── core/                 # Rdzeń logiki gry (postać, ekonomia, czas)
│   ├── gameplay/             # Mechaniki (walka, handel, podróże)
│   ├── graphics/             # Kod związany z renderowaniem (obsługa SFML/Raylib)
│   └── main.cpp              # Główny plik uruchomieniowy
│
├── include/                  # Pliki nagłówkowe (.h, .hpp)
│   ├── core/
│   ├── gameplay/
│   └── graphics/
│
├── data/                     # Dane gry w formacie JSON
│   ├── eras/
│   │   └── 14th_century/
│   │       ├── items.json
│   │       ├── events.json
│   │       └── ...
│   └── game_config.json
│
├── assets/                   # Zasoby graficzne i dźwiękowe
│   ├── fonts/
│   ├── images/
│   └── sounds/
│
├── lib/                      # Zewnętrzne biblioteki (np. SFML)
│
└── CMakeLists.txt            # Główny plik konfiguracyjny CMake
```

## 4. Podstawy Mechaniki Gry
(Sekcja pozostaje bez zmian, mechaniki są niezależne od technologii).

### 4.1. Postać i Statystyki
### 4.2. Ekwipunek i Zasoby
### 4.3. System Losowych Zdarzeń

## 5. Plan Rozwoju (Roadmap)
Plan rozwoju zostanie dostosowany do nowej wizji, z priorytetem na stworzenie rdzenia logiki w C++ i podstawowej warstwy graficznej.