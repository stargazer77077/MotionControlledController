### Space Invaders Controller
<li>Improvements</li>

The 3 improvements my teammate and I chose are decouple firing and movement, smoother movement, and movement speed control.

For the first improvement, instead of using the downward orientation of the board as the signal for firing, which leads to the issue that moving the spaceship and firing cannot be synchronous, we chose to build a button on the board using it as the trigger. By doing so, we are able to decouple firing and movement.

For the second improvement of smoother movement, after observing the reading of the accelerometer readings when we tilted the board, my teammate and I determined thresholds for the control of left and right motion. By doing so, the controller is no longer prone to volatile movement due to slight changes in orientation.

For the third improvement of movement speed control, after my teammates and I tried out the game, we found that it is more favorable to have the ship move at different speeds so that at fast speed we could dodge the bullets of enemy ships with ease, while at low speed we would have more precision of firing. To implement this improvement, we decided to set another threshold for the readings of the accelerometer and send the command either left or right depending on the orientation twice in one execution of the controller program. The logic behind is that when we are dodging enemy fire, we tilt the board more than normally maneuvering the ship, which results in higher readings of the accelerometer.
<li>Features</li>

The three features my teammates and I added are LED feedback, current score display, and quitting the game.

For the first feature, we decided that the feedback of getting shot would give us a more immersive gameplay. The form of feedback we chose was to light a red LED whenever our spaceship was hit. To implement it,  we sent data containing the information whether the out ship was hit to the socket and monitored the data the socket received, and if "HIT" was present, the socket would communicate with the MCU and blink the red LED.

The second feature we chose was to display the current score on the OLED display of the controller. The logic behind is to keep track of the score even when playing easier, especially when we are looking at the controller to find the button. To implement it, once we hit an enemy ship, we sent data containing the updated score from the game to the socket. The socket would then communicate with the MCU and display the current score on the OLED screen.

The third feature we chose was to quit the game using the photodetector. The logic behind is instead of pressing "Ctrl+C" to exit the game, we could use the board for easier exiting. To implement it, we detect whether the photodetector is covered, and how long it has been covered by looking at the readings of the sensor. If the photodetector is covered. The MCU would then send the message "QUIT" to the socket, and then the socket would tell the game program to exit out of execution.

<li>Instructions</li>
To turn ON/OFF controller: Controller needs to be paired with computer to function. After establishing a connection, run space_invaders_controller.py to turn on the controller. Next, run spaceinvaders.py to start playing. To turn off controller, end execution of space_invaders_controller.py.

Determining Status: OLED screen will display "ON" when the controller is ready to function. The OLED screen will display "OFF" when the controller is turned off. During game play, the OLED display would show the current score.

Direction Control: To control the direction of movement of the spaceship, tilt the controller in the direction of interest. A small tilt angle would give normal moving speed, while a large tilt angle would give a faster moving speed.

Firing: Hold button down to fire.

Quiting the game: Cover the photodetector for a short period of time to quit the game.

LED: LED would blink when the player's ship has been hit.

<li>Link To Video</li>
The link containting the video to this challenge can be found here: https://youtu.be/c6CdrG9LeKo

### Division of Work

My teammates and I distributed the workload in a reasonable manner so that we both are able to benefit from this project. The detailed work division is as follows.

<li> Space Invaders Controller </li>

| Item  | Person |
| ------------ | ----------- |
| Arduino Code for smoother movement | W.H. |
| Arduino Code for decoupling firing and movement| X.H. |
| Realization of speed control    | X.H. |
| Arduino & Python code for quitting game via Photo-detector |W.H. |
| Arduino & Python Code for LED feedback | Team |
| Python Code for displaying current score | Team |
