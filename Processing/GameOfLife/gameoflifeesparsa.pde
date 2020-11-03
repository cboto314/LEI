final int cellSide = 16;
final int terrainColumns_i = 40;
final int terrainRows_i = 30;
final int windowWidth = terrainColumns_i * cellSide;
final int windowHeight = terrainRows_i * cellSide;
final int terrainColumns = 1000;
final int terrainRows = 1000;
 
Terrain t;
boolean running;
 
void setup() {
 
  t = new Terrain();
  running = false;
  surface.setResizable(true);
 
}
 
void settings(){
 
      size(windowWidth,windowHeight);
 
}
 
void mouseClicked() {
 
  t.mouseClicked(mouseX, mouseY);
 
}

void mouseDragged(){
 
  t.mouseDragged();
  
}

void mouseReleased(){
 
  t.mouseReleased();
  
}
 
void keyPressed() {
   if (key == ENTER)
     saveFrame("flood-####.jpg");
   else if (key == 'R')
     running = true;
   else if (key == '!')
     running = false;
   else if (key == 'O')
     selectInput("Open file:", "fileRead");
 }
 
void fileRead(File f) {
    if (f == null)
        println("Window was closed or the user hit cancel.");
    else
        t.loadMap(f.getAbsolutePath());
 }
 
/////////////////////////////////////

boolean in_array(PVector a[], PVector c){
 
  for(int i=0; i < a.length; i++)
    if(a[i].x == c.x && a[i].y == c.y)
      return true;
  
  return false;
}

PVector[] remove_from_array(PVector old[], PVector c){
  
  PVector result[] = new PVector[0];
  
  for(int i = 0; i < old.length; i++)
    if(old[i].x != c.x || old[i].y != c.y)
      result = (PVector[]) append(result,new PVector(old[i].x,old[i].y));
  
  return result;
  
}


///////////////////////////////////// 
 
class Terrain {  
 
   //int map[][];
   PVector cells[] = new PVector[0];
   PVector ngbs[] = new PVector[0];
   
   boolean drag = false;
   int x_offset = 0;
   int y_offset = 0;
 
    void update()   {
         ngbs = new PVector[0];
         ngbs = get_neighbours(cells);
         
         cells = expand();

//         println("len ngbs => "+ngbs.length);
  //       println("len cells => "+cells.length);
    //     println("\n\n");

        //for(int i = 0; i < cells.length; i++)
          //println("x => "+cells[i].x+" || Y => "+cells[i].y);

      }
     
     
 void mapFromStrings(String a[]){
     for (int i = 0; i < a.length; i++)
     {
       String tokens[] = split(a[i], " ");
       int x = int(tokens[0]);
       int y = int(tokens[1]);
//       map[y][x] = 0;
       cells = (PVector[]) append(cells, new PVector(x,y));
     }
   }
 
 void loadMap(String filename){
     println(filename);
     String[] lines = loadStrings(filename);
     println("Lines read: ", lines.length);
     for(int i = 0; i < lines.length; i++)
       println(lines[i]+"\n");
     mapFromStrings(lines);
   }    
 
 PVector[] get_neighbours(PVector c[]){
   
    PVector[] result = new PVector[0];
   
    for(int i = 0; i < c.length; i++){
      if(!in_array(cells,new PVector(c[i].x-1,c[i].y-1)))
        result = (PVector[]) append(result,new PVector(c[i].x-1,c[i].y-1)); //upperleft
        
      if(!in_array(cells,new PVector(c[i].x-1,c[i].y)))                  //above
        result = (PVector[]) append(result,new PVector(c[i].x-1,c[i].y));
        
      if(!in_array(cells,new PVector(c[i].x-1,c[i].y+1)))                //upper-right
        result = (PVector[]) append(result,new PVector(c[i].x-1,c[i].y+1));
        
      if(!in_array(cells,new PVector(c[i].x,c[i].y-1)))              //left
        result = (PVector[]) append(result,new PVector(c[i].x,c[i].y-1));
        
      if(!in_array(cells,new PVector(c[i].x,c[i].y+1)))              //right
        result = (PVector[]) append(result,new PVector(c[i].x,c[i].y+1));
        
      if(!in_array(cells,new PVector(c[i].x+1,c[i].y-1)))              //lower left
        result = (PVector[]) append(result,new PVector(c[i].x+1,c[i].y-1));
        
      if(!in_array(cells,new PVector(c[i].x+1,c[i].y)))              //below
        result = (PVector[]) append(result,new PVector(c[i].x+1,c[i].y));
        
      if(!in_array(cells,new PVector(c[i].x+1,c[i].y+1)))              //lower right
        result = (PVector[]) append(result,new PVector(c[i].x+1,c[i].y+1));
      
    }
      
   return result;
   
 }
 
  int countNeighbours(PVector []c,int i){
   
        int result = 0;

     //for(int i = 0; i < c.length; i++){
      if(in_array(cells,new PVector(c[i].x-1,c[i].y-1)))
        result++;// = (PVector[]) append(result,new PVector(c[i].x-1,c[i].y-1)); //upperleft
        
      if(in_array(cells,new PVector(c[i].x-1,c[i].y)))                  //above
        result++;// = (PVector[]) append(result,new PVector(c[i].x-1,c[i].y));
        
      if(in_array(cells,new PVector(c[i].x-1,c[i].y+1)))                //upper-right
        result++;// = (PVector[]) append(result,new PVector(c[i].x-1,c[i].y+1));
        
      if(in_array(cells,new PVector(c[i].x,c[i].y-1)))              //left
        result++;// = (PVector[]) append(result,new PVector(c[i].x,c[i].y-1));
        
      if(in_array(cells,new PVector(c[i].x,c[i].y+1)))              //right
        result++;//= (PVector[]) append(result,new PVector(c[i].x,c[i].y+1));
        
      if(in_array(cells,new PVector(c[i].x+1,c[i].y-1)))              //lower left
        result++;// = (PVector[]) append(result,new PVector(c[i].x+1,c[i].y-1));
        
      if(in_array(cells,new PVector(c[i].x+1,c[i].y)))              //below
        result++;// = (PVector[]) append(result,new PVector(c[i].x+1,c[i].y));
        
      if(in_array(cells,new PVector(c[i].x+1,c[i].y+1)))              //lower right
        result++;// = (PVector[]) append(result,new PVector(c[i].x+1,c[i].y+1));
      
    //}
       
        return result;
   
  }
 
 /* int*/ PVector[] expandCell(PVector n_c[]){

      PVector[] n_c2 = new PVector[0];   

      
   for(int i = 0; i < n_c.length; i++){
        int nbs = this.countNeighbours(n_c,i);
      if(in_array(cells,new PVector(n_c[i].x,n_c[i].y))){
       
        if(!(nbs < 2 || nbs > 3))
            n_c2 = (PVector[]) append(n_c2,new PVector(n_c[i].x,n_c[i].y));  

        
      }
      else
      if(in_array(ngbs,new PVector(n_c[i].x,n_c[i].y))){
        if(nbs == 3)
          n_c2 = (PVector[]) append(n_c2,new PVector(n_c[i].x,n_c[i].y));          

      }
      }
      return n_c2;
   }
 
 PVector[] expand(){


  PVector new_cells[] = new PVector[0];
  PVector new_cells2[] = new PVector[0];
  
//  println("len ngbs => "+ngbs.length);

     new_cells = expandCell(cells);
   
     new_cells2 = expandCell(ngbs);

      println("len new c "+new_cells.length);
      println("len new c 2 "+new_cells2.length);
      
      for(int i = 0; i < new_cells2.length; i++){
        if(!in_array(new_cells,new_cells2[i]))
          new_cells = (PVector[]) append(new_cells,new_cells2[i]);
      }
      
     //return (PVector[]) concat(new_cells,new_cells2);
     return new_cells;
  
 }  
 
 void drawCells()   {
     noStroke();    
 
      
           
      for(int i = 0; i < cells.length; i++){
        fill(yellow);

        rectMode(CORNER);          
        square(cells[i].y * cellSide, cells[i].x * cellSide, cellSide);    
        
      }
     /* ngbs = get_neighbours(cells);
      
       for(int i = 0; i < ngbs.length; i++){
       // println("X = "+cells[i].x+" || Y = "+cells[i].y);
        fill(green);

        rectMode(CORNER);          
        square(ngbs[i].y * cellSide, ngbs[i].x * cellSide, cellSide);    
       */ 
//      }
        
 }
 
  color pickColor(int x) {
 
  return HTMLColors[x % HTMLColors.length];
 
}
 
  void mouseClicked(int x, int y)   {
      int row = y / cellSide;
      int column = x / cellSide;
      if(!in_array(cells, new PVector(row,column))) 
        cells = (PVector[]) append(cells, new PVector(row,column));
      else
        cells = remove_from_array(cells, new PVector(row,column)); 
    }
 
 
  Terrain()   {

              
//     ngbs = get_neighbours(cells);
  }
         
  void mouseDragged(){
    
     drag = true; 

    
  }
 
 void mouseReleased(){
  
   if(drag){
    drag = false;
    for(int n = 0; n < cells.length; n++){
     cells[n].y += (int)map(mouseX,0,width,-10,10);
     cells[n].x += (int)map(mouseY,0,height,-10,10);
    }
    

   }
      
 }
  
   
// }
 
void drawGrid()   {
    stroke(100);    
    strokeWeight(1);    

   
   for(int i = 1; i < height/cellSide; i++)
       line(0 + x_offset, i*cellSide + x_offset,  width + x_offset, i*cellSide + x_offset);
   for(int j = 1; j < width/cellSide; j++)
      line(j*cellSide + y_offset, 0 + y_offset, j*cellSide + y_offset,  width + y_offset);  

   
 }
 void draw()   {
     drawCells();
    // if (countUpdate == 0)
       drawGrid();  
 }
 
}
 
float hertz = 4.0;
 
void update() {
    t.update();
  }
 
void draw() {
 
   if (running)   {
       if (frameCount % max(25, int(frameRate / hertz)) == 0)
           update();  
      }  
   background(darkgray);
   t.draw();
}
