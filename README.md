# Zadanie z programowania w języku ROOT

## Wymagania wstępne

- Instalacja oprogramowania ROOT (szczegóły w linku: [ROOT Installation](https://root.cern/install/))

## Klonowanie repozytorium

```
git clone <link do repo>
```

## Załadowanie makr

```
root
.L LoadMacros.C
LoadAllMacros()
```

## Wywoływanie makra

- `WidmoCs("<nazwa_pliku>")` - argument domyślny to "Cs-137.dat". Tworzy histogram w ROOT z podanego pliku z danymi, zapisuje wynik w pliku ROOT i PNG.
- `Rewrite("<nazwa_pliku>")` - argument domyślny to "Cs-137.dat". Przepisuje dane z pliku do formatu binarnego, wyświetla zawartość.
- `WidmoCsBin("<nazwa_pliku>")` - argument domyślny to "Cs-137.bin". Tworzy histogram w ROOT z podanego pliku binarnego, zapisuje wynik w pliku ROOT i PNG.
- `DrawHistograms()` - tworzy histogramy 2D i 3D dla czterech przykładowych rozkładów (dane generowane losowo).

## Troubleshooting

W przypadku błędu, warto spróbować uruchomić ponownie program ROOT:

```
.q
root
```

Następnie powtórzyć kroki załadowania makr i wywołania wybranego makra.
