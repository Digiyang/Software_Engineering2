// Simo Teil
2. Fügen Sie eine neue Klasse hinzu, die folgende Eigenschaften erfüllt

    Sie realisiert die vorgegebene Schnittstelle Engine
    Sie hat keine Abhängigkeiten von Qt (kein include, nichts aus Qt benutzen, die Klasse Calculator nicht kennen)
    Alle mathematischen Berechnungen an Stelle von Calculator ausführt (sowohl unäre, als auch binäre Operatoren)
    Die den Zustand von accumulator_, pendingOperator_ und memory_ intern kapselt (diese sind danach nicht mehr in Calculator zu finden)
    Die Fehlerbehandlung mit Hilfe von Exceptions (z.B. ParameterException) durchführt

// Moez Teil
3. Modifizieren Sie die Calculator Klasse so, dass:

    Im Konstruktor ein Engine *, der auf eine Instanz von Ihrer abgeleiteten Klasse zeigt, übergeben wird
    Kein import von <cmath> im Header oder der Implementierung vorhanden ist
    Keine mathematischen Berechnungen oder Überprüfungen von Vorbedingungen für die Berechnungen durchgeführt werden
    Die Klasse immer noch für die Benutzer-Interaktion zuständig ist und ...
    ... weiterhin die Funktionalität für das Warten auf den nächsten Operanden besitzt, sowie ...
    ... immer noch die Anzeige und Modifikation des aktuellen Eingabewerts (als Zeichenkette in display_) vornimmt.
    Die eigentliche Funktionalität sich dabei nicht ändert, sondern nur an die Engine delegiert wird.
