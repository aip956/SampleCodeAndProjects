It's like Moving Box and the Windows screen saver. When the box hits a side, it bounces in the opposite direction.

I found this challenging because I did not use a separate variable in Moving Box for the change increment. But I needed to change the direction, so needed another variable that would change once the box position was 0 or the view height/width.

I also originally used the min-width and min-height to define the box dimensions. This was incorrect; it needs to be clientWidth and clientHeight to accommodate responsive sizing.

LOGIC
Define left and top positions, width and height of box, view width and height, and x and y position changes
Increment/decrement x and y position until either hits x 0 or view width, or y hits 0 or view height 
Once it does, change the x or y position change to the opposite direction

