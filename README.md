# MQTT-Node-Red-Projekt-f-r-Schule

Wichtige Begriffe:

    MQTT-Broker: Die zentrale Schaltstelle (Server). Er empfängt alle Nachrichten und verteilt sie an die interessierten Empfänger.

    MQTT-Client: Jedes Gerät (ESP32, PC, Smartphone), das mit dem Broker verbunden ist.

    Publish (Veröffentlichen): Ein Client sendet Daten an den Broker unter einem bestimmten "Topic".

    Subscribe (Abonnieren): Ein Client teilt dem Broker mit, dass er über Nachrichten zu einem bestimmten "Topic" informiert werden möchte.

    Topic: Die Adresse der Nachricht (ähnlich einer Ordnerstruktur, z.B. haus/flur/temperatur).

    Payload: Der eigentliche Inhalt der Nachricht (z.B. 22.5).

    QoS (Quality of Service): Bestimmt die Zustellgarantie (0: Maximal einmal, 1: Mindestens einmal, 2: Genau einmal).

MQTT Broker Mosquitto -> Raspberry-Pi Lan: 

    Sind auf die Mosquitto seite und haben die Exe heruntergeladen. 
    Nach denn Insterlieren von Mosqitto öffnest du Mosqitto.config in editor.
    Am ende der Datei haben wir 2 Seiten hinzugefügt mal listenee 1883 der ermöglicht den zugrief über das Netzwerk auf port 1883 der zweite allow_anneoymous true das erlaubt die Verbindung ohne Benutzername und Passwort.

    Wir haben den Broker als Windows dienst gestartet.
    Dafür haben wir Windos+r gedrückt und Services.msc eingegeben. 
    Dann haben wir den Mosqitto Broker gesucht und diesen neu gestartet damit unsere Config änderung damit sie übernommen werden. 
    Als letzten schritt haben wir die Windows firewale angepasst so das unser enternes Gerät den erreichen können, dafür haben wir den Windows defender firewal mit erweiterter sicherheit gestartet und in den eingehenden regeln eine neue Regel erstellt.

    Jetzt prüfen wir mit dem MQTT-Explorer ob unser MQTT Broker ordnungsgemäß funktioniert.
    Dafür haben wir den MQTT-Explorer heruntergeladen und die Standart Instalation ausgeführt.

3.1: 

    Wir haben den Clietn mit unseren Windows Broker verbunden und haben folgende sachen eingegeben
    Host: localHost
    Port: 1883
    Protokoll: mqtt://
    Username/Passwort: haben wir leer gelassen das wir allow_anomynus true gesetzt haben

    Bei Erfolg kommt folgende Übersicht: "Bild hinzufügen"

    Als nächstes muss Publish-nachricht getest werden, dafür geht man im MQTT-Explorer auf das Feld publish dort gibt man im Feld topic ein test pfad ein bsp.: ags/projekt/test
    Als payload wählt man raw oder text und schreibt eine Nachricht.
    Dann klicken auf publish.
    Wenn alles erfolgreich ist sieht man jetzt links im Hierachiebaum unter ags -> projekt -> test die Nachricht  

4: 

     

Entwicklerdokumentation:

Zwischenstand:

    aufgabe 4 von 14 
    doku fortschritt 3 von 4 
    
    
