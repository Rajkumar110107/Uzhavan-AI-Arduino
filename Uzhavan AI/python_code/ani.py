import serial
import time
import os
import webbrowser
from gtts import gTTS
import pygame

# -------- SETTINGS --------
COM_PORT = "COM9"
BAUD_RATE = 9600

LAT = 12.960546930204591
LON = 80.05694738163028

AUDIO_FILE = "animal_alert.mp3"
TAMIL_TEXT = "கவனம்! வயலில் விலங்கு கண்டறியப்பட்டது"
# --------------------------

arduino = serial.Serial(COM_PORT, BAUD_RATE, timeout=1)
time.sleep(2)

# create Tamil voice file once
if not os.path.exists(AUDIO_FILE):
    tts = gTTS(text=TAMIL_TEXT, lang="ta")
    tts.save(AUDIO_FILE)

pygame.mixer.init()

print("Uzhavan AI Animal Monitoring Started...\n")

last_state = "CLEAR"

while True:

    data = arduino.readline().decode("utf-8", errors="ignore").strip()

    if not data:
        continue

    print("Sensor:", data)

    # Animal detection alert
    if data == "ANIMAL DETECTED" and last_state != "ANIMAL DETECTED":

        print("⚠ Animal detected!")

        pygame.mixer.music.load(AUDIO_FILE)
        pygame.mixer.music.play()

    # Button pressed → open Google Maps
    elif data == "GET_LOCATION":

        print("📍 Opening Google Maps...")

        map_url = f"https://www.google.com/maps?q={LAT},{LON}"

        webbrowser.open(map_url)

    last_state = data