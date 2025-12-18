# MQTT-Node-Red-Projekt-f-r-Schule

Wichtige Begriffe:

    MQTT-Broker: Die zentrale Schaltstelle (Server). Er empfängt alle Nachrichten und verteilt sie an die interessierten Empfänger.

    MQTT-Client: Jedes Gerät (ESP32, PC, Smartphone), das mit dem Broker verbunden ist.

    Publish (Veröffentlichen): Ein Client sendet Daten an den Broker unter einem bestimmten "Topic".

    Subscribe (Abonnieren): Ein Client teilt dem Broker mit, dass er über Nachrichten zu einem bestimmten "Topic" informiert werden möchte.

    Topic: Die Adresse der Nachricht (ähnlich einer Ordnerstruktur, z.B. haus/flur/temperatur).

    Payload: Der eigentliche Inhalt der Nachricht (z.B. 22.5).

    QoS (Quality of Service): Bestimmt die Zustellgarantie (0: Maximal einmal, 1: Mindestens einmal, 2: Genau einmal).
