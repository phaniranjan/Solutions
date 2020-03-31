#Lexicographic string comparison

NUM_PLAYERS = 5 # number of players as constant

print("Number of Players", NUM_PLAYERS)

playerNamesList = [] # declaring a list for player names

#loop through loop to read 5 players from user

for i in range (0,NUM_PLAYERS):

    playerName = str(input("Enter the Player Name: "))

    playerNamesList.append(playerName)

# initializing firstplayer and its index at the begining of list

    firstPlayer = playerNamesList[0]

    firstPlayerIndex = 0

#loop through to find Lexicographic bigger player and mark him as first player who gets turn

for i in range(1,NUM_PLAYERS):

    if(firstPlayer < playerNamesList[i]):

        firstPlayer = playerNamesList[i]

        firstPlayerIndex = i

        print("Player {} is \'IT\' at index {}".format(firstPlayer,firstPlayerIndex))

#replacing first player with ''

        playerNamesList[firstPlayerIndex]=''

        print("At start of game: ",playerNamesList)
