


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	int response;
	int randNum;
	srand(time(NULL));

	cout << "Welcome to the adventure of a life time. Discover great riches or an early demise. Continue only with great caution. Danger lurks around every corner. Enter:" << endl;
	cout << "1) Continue, if you dare." << endl;
	cout << "2) Quit and run away scared." << endl;
	cin >> response;
	cout << endl;
	
	//You play the game
	if (response == 1) {
		cout << "You awake lying on the ground in a dark room. As you begin to sit up you feel a stabbing pain rush through your head. You lie back down and try to remember what happened to you. You realize you cannot even remember where you came from, or who you are! You begin to panic, but here a loud swirling noise coming from your right. You slowly stand up and look to see what the source of the sound is. As your eyes adjust to the darkness, you see a grey liquid suspended in the air swirling in a clockwise direction. You feel a strong curiosity to approach the liquid. Before you do so, you continue to look around and realize you are actually in a cave. Directly opposite of the swirling liquid is a tunnel leading deeper into the cave. What will you do?" << endl;
		cout << "1) Approach the swirling liquid." << endl;
		cout << "2) Take the tunnel deeper into the cave." << endl;
		cin >> response;
		cout << endl;
		
		//You approach the portal
		if (response == 1) {
			cout << "The sound of the moving liquid fills your ears and curiosity overtakes you. You approach it slowly and feel drawn to it. You get closer and closer until you are standing directly in front of it. You reach out your hand to touch it and the rest of your body is pulled forward. You feel yourself pass through the liquid and a bright light fills your vision..." << endl;
			
			//A random number is generated to determine where you will go
			randNum = rand() % 11;
			
			//Rand nums 1-7 take you to the countryside
			if (randNum < 8) {
				cout << "As the light clears, you see you have been moved to what appears to be a countryside. Directly in front of you is a field of never ending green grass. Behind you is a thick forest. What will you do?" << endl;
				cout << "1) Frolick gleefully through the field to forget about your odd situation." << endl;
				cout << "2) Scavenge in the forest for supplies." << endl;
				cin >> response;
				cout << endl;

				//Frolick
				if (response == 1) {
					cout << "You gallop freely through the field, enjoying the smell of grass and the feeling of warm sunshine beating down on your face. After about 5 minutes of wild abandon, you come accross what appears to be the only flower in the entire field. What will you do with it?" << endl;
					cout << "1) Crush the flower beneath your foot." << endl;
					cout << "2) Pluck the flower and smell it." << endl;
					cin >> response;
					cout << endl;

					//Crush
					if (response == 1) {
					cout << "You feel like ruining what appears to be the only form of life in the entire field of grass. So you stomp on the flower as hard as you can. You swear you could hear what sounded like a small scream, but when you lift up your foot, you see only the crushed flower, it must have been the wind. The air now has a sweet smell about it. You breathe it in deeply and realize how tired you are. You decide to take a quick nap before continuing. You fall into a deep sleep and dream about having the most wonderful life for all of eternity, never to awake again." << endl;
					cout << "Game Over" << endl;
					}
					//Smell
					else if (response == 2) {
					cout << "You are intrigued by the lone flower and pluck it out of the ground. You hold it close to your face, close your eyes, and take a deep whiff. Strangely, the flower has no smell to it at all. When you open your eyes, you see a mean looking face with pointy teeth staring back at you from the center of the flower. Before you can react, the flower bites you on the nose and continues to bite until there is nothing left to eat." << endl;
					cout << "Game Over" << endl;
					}
				}
				//Scavenge
				else if (response == 2) {
					cout << "You decide to leave the pleasent field behind in order to find some much needed supplies for survival. As you enter the forest, your foot catches on something and sends you tumbling to the ground. Upon further inspection, you find the source of what you tripped on to be a small wooden box. Within the box is a pendent of some kind with three buttons lining the bottom. What would you like to do?" << endl;
					cout << "1) Press button 1." << endl;
					cout << "2) Press button 2." << endl;
					cout << "3) Press button 3." << endl;
					cin >> response;
					cout << endl;

					//Button 1
					if (response == 1) {
						cout << "You choose to press the first button. As you do so, the pendent begins to make a whirring sound and a kind of gas fills the air around you. You drop the pendent and attempt to run, but the gas simply follows. Your breaths get shorter and shallower and before long you cannot breathe at all. Your legs give out and you drop to your knees as blackness fills your vision." << endl;
						cout << "Game Over" << endl;
					}
					//Button 2
					else if (response == 2) {
						cout << "Your hand reaches out and clicks in the second button. Suddenly, a cloud seems to clear from your mind. You begin to remember things about your past. You remember that you are a single, middle-aged man who still lives at home with your mom. She told you that you needed to get a job, so you replied to a craigslist ad that said 'Help Needed'. When you arrived the men knocked you out and left you inside the cave where you woke up. A bright light blinds you once again and you appear in your mom's basement where you live out the rest of your boring life." << endl;
						cout << "Game Over" << endl;
					}
					//Button 3
					else if (response == 3) {
						cout << "You decide to press the third button. A loud trumpet blasts and you hear the noises of animals all around you. They begin to gather around you and you notice a bear who appears to be holding something in its mouth. It approaches you, stands on its hind legs, and takes a crown out of its mouth to place upon your hand. You spend the rest of your days ruling the animals of the forest (which basically involves you doing nothing and having animals bring you food)." << endl;
						cout << "Game Over" << endl;
					}
				}
			}
			//Rand nums 8-10 take you to the underworld
			else if (randNum > 7) {
				cout << "The light fades and is replaced by a dark red glow. You look around and see that you are within a giant cave, but one different from where you just were. There are lava streams coming down from the sky and red brick houses are placed everywhere. A wooden sign in front of you reads 'Welcome to the Underworld!'. Your heart leaps into your throat and you begin to panic. Out of the corner of your eye you see a hulking beast approaching. He is completely red, scaly, and has two great long horns protruding from his head. You quickly realize a demon is approaching. What will you do?" << endl;
				cout << "1) Hold your ground." << endl;
				cout << "2) Run into a nearby house." << endl;	
				cin >> response;
				cout << endl;

				//Hold your ground
				if (response == 1) {
					cout << "You decide to try and impress the demon by holding your ground and looking as fierce as possible. The demon seems unphased and walks right up to you. He moves his arms and legs quickly in a complex pattern. Now what?" << endl;
					cout << "1) Attempt to immitate the demon." << endl;
					cin >> response;

					//Imitate
					if (response == 1) {
						cout << "You attempt to immitate the demon and..." << endl;
						
						//Random number is generated for chance element
						randNum = rand() % 11;
						
						//Rand nums 1-8 your soul gets sucked out
						if (randNum < 9) {
							cout << "instead trip over your own feet and tumble to the ground. The demon towers over you and looks you straight in the eyes. No matter how hard you try, you cannot look away. Your soul is torn away from your body and is absorbed by the demon. You spend all of eternity in endless turmoil." << endl;
							cout << "Game Over" << endl;
						}

						//Rand nums 9-10 become the demon's slave
						if (randNum > 8) {
							cout << "you miraculously imitate the demon perfectly! The demon reaches his hand over you and speaks in a foreign tongue. Suddenly, you can understand exactly what the demon is saying. He tells you that he has granted you immortality for your successfull imitation. However, you must also become his slave or he will kill you instantly. You become the demons slave and live throughout eternity serving him." << endl;
							cout << "Game Over" << endl;
						}
					}
				}
				//Run into the nearest house
				else if (response == 2) {
					cout << "Being terrified by the demon, like any normal person would be, you sprint towards the nearest house. You turn the door knob and find it to be unlocked. You quickly enter and turn around to see the demon continuing to follow you. You slam the door shut and try to decide what to do next." << endl;
					cout << "1) Hide." << endl;
					cout << "2) Search for a weapon." << endl;
					cin >> response;
					cout << endl;

					//Hide
					if (response == 1) {
						cout << "You decide to hide, because that always works out great. You dive under the nearest table and try to hold as still as possible. You hear the door fly open and you know the demon is inside. A hand closes around you leg and drags you out from under the table. The demon holds you above his head and lowers you quickly into his mouth, devouring you with one bit." << endl;
						cout << "Game Over" << endl;
					}
					//Search
					else if (response == 2) {
						cout << "You decide to search for a weapon, because hiding has never worked out great for anyone. You run into the next room and see a glowing sword hanging above the fireplace. You decide to keep searching just in case there is something better but you here the door slamming against the wall. Out of time and options, you rip the glowing sword from off the wall. Turning around, you see the demon standing on the other side of the room. Figuring it is now or never, you rush towards the demon. Raising your sword above your head, you slash downward and..." << endl;
						
						//Random number is generated for element of chance
						randNum = rand() % 11;
						
						//Rand nums 1-9 you get stabbed in the heart by the demon
						if (randNum < 10) {
							cout << "the demon spits a burst of fire from his mouth and melts your sword instantly. As you look down at the hilt of your sword in despair, you feel a pierce where your heart is, or at least where it used to be. You look down and see a gaping hole in your chest. The last thing you see is the demon eating your heart as it is still beating." << endl;
							cout << "Game Over" << endl;
						}
						//Rand num 10 you kill the demon
						if (randNum > 9) {
							cout << "you cut the demon in half straight down the middle. You feel a surge of joy as you watch the two halves fall lifelessly to the ground. Bloodlust fills you and you run into the streets cutting down demons wherever they appear. You catch the attention of Satan himself and he offers to make you his second in command. Unsatisfied, you cut him down as well and become ruler of the underworld." << endl;
							cout << "Game Over" << endl;
						}
					}
				}
			}
		}
		//You go into the cave
		else if (response == 2) {
			cout << "You leave the mysterious grey liquid behind and delve deeper into the cave. After about 5 minutes of walking you come accross a split in the tunnel. Which way will you go?" << endl;
			cout << "1) Left." << endl;
			cout << "2) Right." << endl;
			cin >> response;
			cout << endl;
			
			//You go into the cave, and then go left
			if (response == 1) {
				cout << "You decide to take the left tunnel, based off of absolutely nothing. You keep walking for what seems like an eternity. Your stomach begins to growl and you think your ears and eyes are starting to play tricks on you. Once again, you come to a fork in the tunnel. Which way will you go?" << endl;
				cout << "1) Left." << endl;
				cout << "2) Right." << endl;
				cin >> response;
				cout << endl;
				
				//You go into the cave, go left, and then go left again
				if (response == 1) {
					cout << "You decide to go left again, figuring that if you are in a maze, going left every time may somehow lead to you escaping. Your eyes have adjusted almost completely to the darkness, which is strange since there is absolutely no light reaching into the cave. Your eyes continue to play tricks on you and you think you see forms taking shape in the darkness. You decide to look down and try to move forward as quickly as you can, your heart beating faster and faster. You remind yourself there are no such things as monsters and nothing could possibly be living in this cave. You begin to hear sounds that seem to come from those dark forms. The sounds begin to rise and grow in ferocity. You feel creatures with great claws ripping into your skin from all sides. Pain pierces every point of you, and then dull darkness clouds your eyes." << endl;
					cout << "Game Over" << endl;
				}
				//You go into the canve, go left, and then go right
				else if (response == 2) {
					cout << "You decide to go right, hoping that mixing it up from your last decision will somehow change your current situation. You walk down the tunnel, one foot in front of the other. You have nothing to keep you distracted except for the rhythmic beat of your steps and the growling in your stomach. Time has lost all meaning and seconds meld into hours. The pain in your stomach has grown to an unbearable level and demands your attention. You scratch at the walls and floors till your fingers are bled raw, searching for any morself to satisfy you. All you find is stone that breaks your teeth and leaves you feeling empty. You lay still on the floor, slowlyfeeling your strength being replaced by death." << endl;
					cout << "Game Over" << endl;
				}
			}
			//You go into the cave, and then go right
			else if (response == 2) {
				cout << "You choose to go right, feeling confident in your decision. You walk at a fairly brisk pace, trying to keep your hopes up and stay away from dropping into the abyss of insanity. Your mind still feels void when you consider your past, but you are hopeful that your memory may return on its own. Another fork in the tunnel appears ahead of you. Which way will you go?" << endl;
				cout << "1) Left." << endl;
				cout << "2) Right." << endl;
				cin >> response;
				cout << endl;
				
				//You go into the cave, go right, and then go left
				if (response == 1) {
					cout << "You choose to go left. You walk on and on, finding it harder to keep up your spirit. You feel hopelessness starting to set in and pick up your pace. You fear what will happen if you don't find your way out soon. You watch your feet as they pick their way over the rocks along the ground. You decide to take a break to catch your breath. You lift your eyes off the ground for the first time in a while and see a faint light that begins to fill the cave. You forget about your tiredness and rush towards the light. You break out into glorious light, being blinded at first but welcoming it gladly. However, you cannot shake the feeling of hopelessness you have gathered as you fail to remember who you are. You wander the earth endlessly, unable to find any answers to your past." << endl; 
					cout << "Game Over" << endl;
				}
				//You go into the cave, go right, and then go right again
				else if (response == 2) {
					cout << "You choose to go right, althought you are less confident than before. The darkness and silence begins to seem overwhelming. The rock you have been walking along has given way to what appears to be moss. You decide to take a break and lie your face into the soft plant material. The grumbling in your stomach reminds you of how hungry you are. You pick a piece of the moss and place it in your mouth. It tastes like dirt but it fills you slightly. You feel your mind beginning to slip into insanity. You give up on finding your way out and decide to live out the rest of your days eating moss and crying." << endl;
					cout << "Game Over" << endl;
				}
			}
		}		
	}
	//You quit the game immediately
	else if (response == 2) {
		cout << "Have fun with your boring life..." << endl;
	}
	
}
