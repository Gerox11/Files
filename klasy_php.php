<!DOCTYPE html>
<html lang="en">
<head>
     <meta charset="UTF-8">
     <meta name="viewport" content="width=device-width, initial-scale=1.0">
     <title>Document</title>
</head>
<body>
     <?php
          class Ksiazka{
               public $tytul;
               public $autor;
               public $rokWydania;
               private $dostepna;
               function __construct($tytul, $autor, $rokWydania){
                    $this -> tytul = $tytul;
                    $this -> autor = $autor;
                    $this -> rokWydania = $rokWydania;
                    $this -> dostepna = true;
               }
               function informacje(){
                    echo "Książka: " . $this->tytul . ($this->czyDostepna() ? " - Dostępna" : " - Niedostępna") . " <br>Autor: " . $this->autor . " <br>Rok wydania: " . $this->rokWydania . " <br>";
               }
               function wypozycz(){
                    if($this -> dostepna){
                         $this -> dostepna = false;
                    }else{
                         echo "Książka niedostępna";
                    }
               }
               function zwroc(){
                    $this -> dostepna = true;
               }
               function czyDostepna(){
                    return $this -> dostepna;
               }
          }
          class Czytelnik{
               function __construct(public $imie, private $wypozyczoneKsiazki){
                    $this -> imie = $imie;
                    $this -> wypozyczoneKsiazki = $wypozyczoneKsiazki;
               }
               function wypozyczKsiazke(Ksiazka $ksiazka){
                    if($ksiazka -> czyDostepna()){
                         $ksiazka -> wypozycz();
                         $this -> wypozyczoneKsiazki[] = $ksiazka; 
                    }else{
                         echo $this -> imie . " | Ta książka jest wypożyczona";
                    }
               }
               function pokazWypozyczenia(){
                    foreach($this -> wypozyczoneKsiazki as $ksiazka){
                         echo $this -> imie;
                         echo " - " . $ksiazka -> tytul . "<br>"; 
                    }
               }
          }
          $biblioteka = [new Ksiazka("Harry Potter", "J.K. Rowling", "1997r."), new Ksiazka("Lalka", "B. Prus", "1889r."), new Ksiazka("Balladyna", "J. Słowacki", "1839r."), new Ksiazka("Kamienie na szaniec", "A. Kamiński", "1943r."), new Ksiazka("Opowieść wigilijna", "C. Dickens", "1843r.")];
          foreach($biblioteka as $ksiazki){
               $ksiazki -> informacje();
          }
          $adam = new Czytelnik("Adam", []);
          $dominik = new Czytelnik("Dominik", []);
          $ksiazkaH = $biblioteka[0];
          $ksiazkaL = $biblioteka[1];
          $ksiazkaB = $biblioteka[2];
          $adam -> wypozyczKsiazke($ksiazkaH);
          echo "<br>";
          $adam -> wypozyczKsiazke($ksiazkaB);
          $dominik -> wypozyczKsiazke($ksiazkaB);
          $dominik -> wypozyczKsiazke($ksiazkaL);
          echo "<br>";
          $adam -> pokazWypozyczenia();
          $dominik -> pokazWypozyczenia();
          echo "<br><br>";
          foreach($biblioteka as $ksiazki){
               $ksiazki -> informacje();
          }
     ?>
</body>
</html>