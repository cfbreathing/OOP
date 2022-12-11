## Room type

There are 4 kinds of rooms in the castle:

|    Type     |                                                 Description                                                  |
| :---------: | :----------------------------------------------------------------------------------------------------------: |
|    Lobby    | When you enter the game you will come here first and when you find the princess you will need to return here |
| Normal room |                               A general room, numbered in order of exploration                               |
| Secret room |                                    The princess is hidden here, find her                                     |
| Scary room  |                                 The monster is here, don't get caught by it                                  |

## Legal input

> ***leave***: When you are in lobby, you can input *leave* to quit the game.

> ***go*** {***direction***}: The player goes into the room to the direction. There are four directions here:*north*, *south*, *west*, *east*. You can see which direction you can go by the 
> image. Likewise, the player go to one room, and the program outputs:
>  ```shell
>  Welcome to room 2. There are 2 exits.
>   _____
>  |     |
>        |
>  |__ __|
>  ```
> This means you can go *west* or *south*
> 

> ***quit*** or ***q*** or ***Q***: quit the game.

## Compile & Run

```shell
$ g++ Assignment_003_Adventure.cpp -o Assignment_003_Adventure
$ .\Assignment_003_Adventure
```

## Notion

  1. Each room is randomly generated and its variables are not initialized until after entry.
  2. You can return to a room you have already explored and no new rooms will be created.
  3. The game guarantees that you will definitely find the princess before you meet the monster.

