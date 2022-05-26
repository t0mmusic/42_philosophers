# 42_philosophers
Figuring out Threads
## Purpose
This project introduces threads using a classic computer science problem.
A number of philosophers are gathered in a room with a round table at the centre. 
On the table there is a large bowl of spaghetti, and a number of forks equal to the number of philosophers.
The philosophers will eat, sleep and think. In order two eat, they must take 2 forks. If they cannot eat before they starve, the simulation ends.
<br/><br/>
Each philosopher is running on its own thread, and each fork is represented by a mutually exclusive key, or mutex.
Mutexes can only be accessed by one thread at a time, so each philosopher can only access a fork that isn't being used by another philosopher.
<br/>
In our version, the forks are spread evenly around the table, and each philosopher only has access to two specific forks, one on their left and one on their right.
The arguments this program will take are:<br/><br/>
Number of philosophers<br/>
Time until a philosopher starves<br/>
  Time it takes for a philsopher to eat<br/>
  Time it takes for a philosopher to sleep<br/>
  Times a philosopher eats before the simulation ends (optional)<br/><br/>
  The goal of the project is to make the philosophers survive indefinitely, if possible.
  ## Bonus
  The philosophers can now access any fork they want. Instead of mutexes, we are now using semaphores.
  Semaphores have a number value associated with them, which when it reaches zero, means no other process can access the semaphore.
  The semaphore representing the forks begins with the same value as the number of philosophers. As philosophers take forks, the value decreases.
  Once it hits zero, philosophers can no longer access the forks.<br/>
  In this version, each philosopher is a seperate process, and the only thing shared between them are the semaphores. The same rules of survival apply.
  ## Status
  Complete! Passes mandatory and bonus with a top score of 125.
