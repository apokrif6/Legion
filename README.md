# Unreal Engine BT's changing based on states. Proof of concept

<h3>When to use:</h3>

- When you want to create a lot of small generic BTs and combine them for AI characters
- When you want to create AI characters with interaction based logic. Interactions could be used as states
- When you want to have same behavior for some states for all AI characters (for example, Disabled/Stunned state)
- When you want to try something new :)

<h3>Main concept:</h3>

- AI character has specific controller
- Controller has map with different behaviors based on states
- Every state has own BT
  
![States Behaviors](https://github.com/apokrif6/Legion/blob/main/media/states.jpg)

<h3>Test implementation:</h3>

- Spawn legioner with "Space". State changes to *Spawning*. BT starts
- After BT is end, it's waiting
- Press "1" to change state to *Attacking*. Old BT is stopped and new one is running
- BT is working until we press "2" to change state to *Blocking*. Old BT is stopped and new one is running
  
![Demo](https://github.com/apokrif6/Legion/blob/main/media/demo.gif)

<h3>How to improve:</h3>

- Buffer for queue of states to change
- Change states conditions implementation
