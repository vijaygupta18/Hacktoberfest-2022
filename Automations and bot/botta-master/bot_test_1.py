# bot_test_1.py
import os

# For read the .env file
from dotenv import load_dotenv

# For connecting to discord
import discord
from discord.ext import commands

# Dot env read
load_dotenv()
TOKEN = os.getenv('DISCORD_TOKEN')

# Create a Bot
bot = discord.Client()

# Handle the on ready event


@bot.event
async def on_ready():
    print(f'{bot.user} has connected to Discord!')

# Run the bot with out secret token
bot.run(TOKEN)
