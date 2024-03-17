# Laudesregiae
So 'ne Art Gebetsmühle, die dir eine Textdatei zeilenweise auf dem Desktop einblendet.

Dieses Programm liest eine Textdatei im Programmordner ein und gibt sie Zeile für Zeile an zufälligen Stellen auf dem Bildschirm aus. Die Einblendedauer wird auf Grundlage der Zeilenlänge berechnet.

Neueste Version: [Herunterladen](https://github.com/Alsweider/Laudesregiae/releases/latest)


<a href="https://www.youtube-nocookie.com/embed/Nv_yalvvuDA?si=FYwCuuhc0HzVsOtq
" target="_blank"><img src="http://img.youtube.com/vi/Nv_yalvvuDA/0.jpg" 
alt="Youtube demo" width="480" height="360" border="10" /></a>

# Anleitung
Im Programmordner ist eine Textdatei Eingabetext.txt enthalten. Nach Start des Programms Laudesregiae.exe wird der Inhalt der Textdatei eingelesen und Zeile für Zeile an zufallsgenerierten Positionen ausgegeben. Der Inhalt der Textdatei kann beliebig verändert werden. 

Sobald die Textdatei durchgelaufen ist, beendet sich das Programm selbständig. Es lässt sich während des Betriebs abbrechen durch Rechtsklick auf das Symbol in der Taskleiste -> Fenster schließen. Alternativ kann der Prozess "Laudesregiae.exe" auch über den Taskmanager beendet werden.

# Einstellungen

![2024-03-17 01_15_51-settings ini - Editor](https://github.com/Alsweider/Laudesregiae/assets/30653982/b00b6e71-cbe7-4115-a8f8-e8bda105d596)

Einstellungen können in der Datei "settings.ini" im Ordner der Anwendung vorgenommen werden. Dazu öffnen Sie die Datei in einem Texteditor und passen die Werte nach Belieben an. 

- Geschwindigkeit: Der Wert "speed" ist standardmäßig auf 143 Millisekunden eingestellt. Er steht für die Anzeigedauer pro Zeichen einer Zeile. Enthält eine Zeile der Textdatei 10 Zeichen (inklusive Leerzeichen), wird sie für 10 mal 143 Millisekunden, also knapp anderthalb Sekunden lang, angezeigt.   
- Zufallsreihenfolge: Um die Zeilen der Textdatei in zufälliger Reihenfolge wiederzugeben, setzen Sie den Wert "random=0" auf "random=1".
- Wiederholung: Um die Textdatei in einer Endlosschleife abzuspulen, setzen Sie den Wert "loop=0" auf "loop=1". Achtung: Das Programm wird sich dadurch nicht mehr von selbst beenden, sondern muss in der Taskleiste oder mit dem Taskmanager geschlossen werden.

 Um die Einstellungen zurückzusetzen, können Sie die Datei "settings.ini" löschen. Sie wird beim nächsten Programmstart neu erstellt. 

# Ist es ein Virus?

Nein, es handelt sich nicht um Schadsoftware, aber Warnungen des Betriebssystems kommen bei neuen Softwareprojekten regelmäßig vor, da diese noch nicht in den Analysedatenbanken vorhanden sind. 

[Virustotal-Analyse](https://www.virustotal.com/gui/file/2c54c04ad9c573b6c49606921f5f4fee3b41a54abc6720d3e287888d0b216575/detection)
