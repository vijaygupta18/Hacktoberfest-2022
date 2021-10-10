import requests
from bs4 import BeautifulSoup as BS
import os
from dotenv import load_dotenv
import spotipy
from spotipy.oauth2 import SpotifyOAuth


load_dotenv()

sp = spotipy.Spotify(
    auth_manager = SpotifyOAuth(
        scope = "playlist-modify-private",
        redirect_uri = "http://example.com",
        client_id = os.getenv("Client_ID"),
        client_secret = os.getenv("Client_Secret"),
        show_dialog = True,
        cache_path="token.txt"
    )
)

user_id = sp.current_user()["id"]
# print(f"\n{user_id}")

date = input("Which year do you want to travel to? Type the date in YYY-MM-DD format: ")

response = requests.get("https://www.billboard.com/charts/hot-100/" + date)

soup = BS(response.text, "html.parser")
song_names_spans = soup.find_all("span", class_=".chart-list__element display--flex chart-element__information__song text--truncate color--primary")
song_names = [song.getText() for song in song_names_spans]
# print(song_names)

song_uris = []
year = date.split("-")[0]
# print(f"\nyear = {year}")

for song in song_names:
    result = sp.search(q=f"track:{song} year:{year}", type="track")
    # print(result)

    try:
        uri = result["tracks"]["items"][0]["uri"]
        song_uris.append(uri)
    except IndexError:
        print(f"{song} doesn't exist in Spotify. Skipped.")

# print(song_uris)

#Creating a new private playlist in Spotify
playlist = sp.user_playlist_create(user=user_id, name=f"{date} Billboard 100", public=False)
# print(playlist)

#Adding songs found into the new playlist
sp.playlist_add_items(playlist_id=playlist["id"], items=song_uris)