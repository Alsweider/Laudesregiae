# Laudesregiae
So 'ne Art Gebetsmühle, die dir eine Textdatei zeilenweise auf dem Desktop einblendet.

<details><summary>Inhalt (Deutsch)</summary>
 
- [Laudesregiae](#laudesregiae)
- [Anleitung](#anleitung)
- [Einstellungen](#einstellungen)
- [Ist es ein Virus?](#ist-es-ein-virus)


</details>

<details><summary>Contents (English)</summary>

- [Laudesregiae (English)](#laudesregiae-english)
- [Instructions](#instructions)
- [Settings](#settings)
- [Is it a Virus?](#is-it-a-virus)


</details>


Dieses Programm liest eine Textdatei im Programmordner ein und gibt sie Zeile für Zeile an zufälligen Stellen auf dem Bildschirm aus. Die Einblendedauer wird auf Grundlage der Zeilenlänge berechnet.

Neueste Version: [Herunterladen](https://github.com/Alsweider/Laudesregiae/releases/latest)


<a href="https://www.youtube-nocookie.com/embed/Nv_yalvvuDA?si=FYwCuuhc0HzVsOtq
" target="_blank"><img src="http://img.youtube.com/vi/Nv_yalvvuDA/0.jpg" 
alt="Youtube demo" width="480" height="360" border="10" /></a>

# Anleitung

Im Programmordner ist eine Textdatei Eingabetext.txt enthalten. Nach Start des Programms Laudesregiae.exe wird der Inhalt der Textdatei eingelesen und Zeile für Zeile an zufallsgenerierten Positionen ausgegeben. Der Inhalt der Textdatei kann beliebig verändert werden. 

Sobald die Textdatei durchgelaufen ist, beendet sich das Programm selbständig. Es lässt sich während des Betriebs abbrechen durch Rechtsklick auf das Symbol in der Taskleiste -> Fenster schließen. Alternativ kann der Prozess "Laudesregiae.exe" auch über den Taskmanager beendet werden.

## Einstellungen

![2024-03-24 07_14_40-settings ini - Editor](https://github.com/Alsweider/Laudesregiae/assets/30653982/7ae20b79-6b3f-4f8b-9226-94646d0839d6)


Einstellungen können in der Datei "settings.ini" im Ordner der Anwendung vorgenommen werden. Dazu öffnen Sie die Datei in einem Texteditor und passen die Werte nach Belieben an. 

- Geschwindigkeit: Der Wert "speed" ist standardmäßig auf 143 Millisekunden eingestellt. Er steht für die Anzeigedauer pro Zeichen einer Zeile. Enthält eine Zeile der Textdatei 10 Zeichen (inklusive Leerzeichen), wird sie für 10 mal 143 Millisekunden, also knapp anderthalb Sekunden lang, angezeigt.   
- Zufallsreihenfolge: Um die Zeilen der Textdatei in zufälliger Reihenfolge wiederzugeben, setzen Sie den Wert "random=false" auf "random=true".
- Wiederholung: Um die Textdatei in einer Endlosschleife abzuspulen, setzen Sie den Wert "loop=false" auf "loop=true". Achtung: Das Programm wird sich dadurch nicht mehr von selbst beenden, sondern muss in der Taskleiste oder mit dem Taskmanager geschlossen werden.
- Pausen: Mit dem Wert "pausetime=1000" wird der zeitliche Abstand zwischen dem Einblenden der einzelnen Textzeilen auf 1000 Millisekunden eingestellt.
- Zufallspausen: Der Wert "pausetimerandom" erhält standardmäßig die gleiche Zeit in Millisekunden wie der Wert "pausetime". Die tatsächliche Pause wird per Zufallsgenerator errechnet und erhält einen zufälligen Wert, der zwischen "pausetime" und "pausetimerandom" liegt. Beispiel: Sie definieren die Werte wie folgt: "pausetime=1000" und "pausetimerandom=5000". Ergebnis: Jede Zeile wird für eine zufällige Zeit zwischen 1 und 5 Sekunden ausgeblendet. Wenn beide Werte gleich sind, hat die Pause eine festgelegte Dauer und der Zufallsfaktor kommt nicht zum Tragen.
- Über den Eintrag "font" lässt sich die gewünschte Schriftart einstellen. Der Wert entspricht dem Namen einer auf dem System installierten Schriftart. Um beispielsweise die Texte in der Schriftart Times New Roman anzeigen zu lassen, ändern Sie den Eintrag "font=Carolingia" zu "font=Times New Roman".
- Farben: Um die Farbe des Textes oder des Hintergrunds einzustellen, legen Sie einen neuen [hexadezimalen Farbwert](https://www.w3.org/TR/css-color-4/#named-colors) für die Einträge colourtext=#AA0000 bzw. colourbackground=#EBD5B3 fest.
- Schriftgröße: Um die Schriftgröße einzustellen, verändern Sie den Wert des Eintrags "fontsize". Standardmäßig ist er auf 30 Punkte eingestellt.

 Um die Einstellungen zurückzusetzen, können Sie die Datei "settings.ini" löschen. Sie wird beim nächsten Programmstart neu erstellt. 

# Ist es ein Virus?

Nein, es handelt sich nicht um ein Schadprogramm, aber Warnungen des Betriebssystems kommen bei neuen Softwareprojekten regelmäßig vor, da diese noch nicht lange genug in den Analysedatenbanken vorhanden sind, um als unbedenklich zu gelten. 

<a href="https://www.youtube-nocookie.com/embed/7Vg6RbkM0n8
" target="_blank"><img src="http://img.youtube.com/vi/7Vg6RbkM0n8/0.jpg" 
alt="Circumvent SmartScreen" width="480" height="360" border="10" /></a>

[Virustotal-Analyse v0.6.0](https://www.virustotal.com/gui/file/1e9e6f79487a4ff00fa903ad3a4000632537de751db027b3f0841b5bb2fe0e2e/detection)

# Laudesregiae (English)

A sort of prayer wheel that displays a text file line by line on your desktop.

This programme reads a text file in the programme folder and displays it line by line at random positions on the screen. The duration of each display is calculated based on the length of the lines.

Latest version: [Download](https://github.com/Alsweider/Laudesregiae/releases/latest)

<a href="https://www.youtube-nocookie.com/embed/Nv_yalvvuDA?si=FYwCuuhc0HzVsOtq
" target="_blank"><img src="http://img.youtube.com/vi/Nv_yalvvuDA/0.jpg" 
alt="Youtube demo" width="480" height="360" border="10" /></a>

# Instructions

A text file named Eingabetext.txt (input text) is included in the programme folder. After launching Laudesregiae.exe, the content of the text file is read and displayed line by line at randomly generated positions. The text file can be modified as desired.

Once the text file has been traversed, the programme will terminate automatically. It can be aborted during operation by right-clicking on the icon in the taskbar -> Close window. Alternatively, the process "Laudesregiae.exe" can also be terminated via the Task Manager.

## Settings 

![2024-03-24 07_14_40-settings ini - Editor](https://github.com/Alsweider/Laudesregiae/assets/30653982/7ae20b79-6b3f-4f8b-9226-94646d0839d6)

Settings can be adjusted in the file "settings.ini" in the application folder. To do this, open the file in a text editor and adjust the values as desired.

- Speed: The "speed" value is set to 143 milliseconds by default. It represents the display duration per character of a line. If a line of the text file contains 10 characters (including spaces), it will be displayed for 10 times 143 milliseconds, which is almost one and a half seconds long.
- Random Order: To display the lines of the text file in a random order, set the "random=false" value to "random=true".
- Repeat: To play the text file in an endless loop, set the "loop=false" value to "loop=true". Note: This will prevent the programme from automatically terminating and it must be closed in the taskbar or with the Task Manager.
- Pauses: The parameter "pausetime=1000" adjusts the temporal interval between the appearance of individual lines of text to 1000 milliseconds.
- Random Pauses: The value "pausetimerandom" defaults to the same time in milliseconds as the value "pausetime". The actual duration is calculated using a random number generator and receives a random value between "pausetime" and "pausetimerandom". For instance: You define the values as follows: "pausetime=1000" and "pausetimerandom=5000". Outcome: Each line will be delayed for a random duration between 1 and 5 seconds. If both values are equal, the pause will have a fixed duration, and the random factor will not come into play.
- In the "font" entry, one can adjust the desired typeface. The value corresponds to the name of a font installed on the system. For instance, to display the text in the Times New Roman typeface, simply alter the "font=Carolingia" entry to "font=Times New Roman".
- Colours: To adjust the colour of the text or the background, simply designate a new [hexadecimal colour](https://www.w3.org/TR/css-color-4/#named-colors) value for the entries colourtext=#AA0000 and colourbackground=#EBD5B3.
- Font size: To adjust the font size, simply modify the value of the entry "fontsize". By default, it's set to 30 points.
  
To reset the settings, you can delete the file "settings.ini". It will be recreated on the next programme start.

# Is it a Virus?

No, it is not malware, but warnings from the operating system are common with new software projects, as they have not been present in the analysis databases for long enough to be considered safe.

<a href="https://www.youtube-nocookie.com/embed/7Vg6RbkM0n8
" target="_blank"><img src="http://img.youtube.com/vi/7Vg6RbkM0n8/0.jpg" 
alt="Circumvent SmartScreen" width="480" height="360" border="10" /></a>

[Virustotal Analysis v0.6.0](https://www.virustotal.com/gui/file/1e9e6f79487a4ff00fa903ad3a4000632537de751db027b3f0841b5bb2fe0e2e/detection)
