PVector [] findTargets (int n, PImage img)
{
  img.loadPixels();
  println ("find target");
  PVector [] target = new PVector [n];

  PVector pos;
  for (int i = 0; i < target.length; i++)
  {
    //println (i);
    pos = target (img.pixels, (int) random (img.width), (int) random (img.height), img.width, img.height, 0);

    target [i] = pos;
  }

  return target;
}

PVector target (int [] colors, int x, int y, int W, int H, int depth)
{
  PVector pos = new PVector (0, 0);
  int index = y*W+x;
  color c = colors [index];

  // println ("c: " + red (c) + ", " + green (c) + ", " + blue (c));
  if (depth == 15 || isValidTarget (brightness (c)))
  {
    pos.x = x;
    pos.y = y;

    // print (pos);
  } 
  else 
  {
    pos = target (colors, (int) random (W), (int) random (H), W, H, depth++);
  }
  
    return pos;
}

boolean isValidTarget (float fbrightness)
{
  if (fbrightness > 220) return false;
  float value = map (fbrightness, 0, 255, 1, 200);
  // println (value);

  float iRandom = random (0, value);
  //println (value + ", " + iRandom);
  if (iRandom <= 1) return true;
  else return false;
}