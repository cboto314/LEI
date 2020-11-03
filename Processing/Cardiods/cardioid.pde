int windowWidth = 500;
int windowHeight = 500;

int rad = min(windowWidth,windowHeight);

color bgcolor;
color l_color;

float sF = 1.0;

boolean running = false;

//////////////////////////////////////////////////////
void keyPressed() {
   if (key == ENTER)
     saveFrame("cardioid-####--"+c.k+".png");
 
  // else if (key == 'R')
     //running = true;
   else if (key == '!')
   if(running)
     running = false;
     else
     running = true;
     
     else
     if(key == CODED && keyCode == RIGHT)
      c.k++;//c.update();
      else
           if(key == CODED && keyCode == LEFT)
           c.k--;

       
}  
   

////////////////////////////////////////////////////
class Circle{
 
  float radius;
  float x = windowWidth/2.0;
  float y = windowHeight/2.0;
  //float x;
  //float y;

  
  Circle(float r){
   
    this.radius = r;
   // this.x = get_x();
   // this.y = get_y();
    
  }
  
  float get_x(){
   //println(width);
    return width/2.0; 
   //println(width);
  }
  
  float get_y(){
   return height/2.0; 
  }
  
  
  void draw(){
   
    stroke(8);
    fill(bgcolor);
    circle(x,y,radius);

  } 
  

  
}

class Cardioid extends Circle{
 
  float points[] = new float[0];
  PVector pt_coords[];
  int k;
  
  int n;
  
  
  Cardioid(int n, int k){


    super(rad*sF);
    this.n = n;
    this.k = k;
    
    this.get_points(n);

 }
 
 void get_points(int n){
   for(int i = 0; i < n; i++){
    
     float theta = get_angle(i,n);
     points = (float[]) append(points, theta);
   }
   
 }
 
 float get_angle(int i , int n){
  
   return ((TWO_PI/(float)n) * (float) i) +PI;
   
 }
 
 void get_coords(){
  
   pt_coords = new PVector[0];
   for(int i = 0; i < points.length; i++){

     float x_cord = this.x + radius/2.0*cos(points[i]);
     float y_cord = this.y + radius/2.0*sin(points[i]);
     pt_coords = (PVector[]) append(pt_coords, new PVector(x_cord,y_cord));
   }
   
 }
 
 void draw(){
   this.get_coords();
    stroke(l_color);
    fill(bgcolor);

  

    circle(x,y,radius);
 // ellipse(width/2.0, height/2.0, radius*2.0, radius*2.0);
  
    draw_lines();
   
 }
  
  void draw_lines(){
   // norm(dist(x,y,centerX,centerY),0,maxDist);
    //lerpColor(color(0,0,255), color(255,0,0), norm);
   
    for(int i = 0; i < pt_coords.length; i++){
     int target = abs(((int)(i*k))%n);
     stroke(l_color);
     //stroke(8);
     line(pt_coords[i].x,pt_coords[i].y,pt_coords[target].x,pt_coords[target].y);
      
    }
    
    println(k);
  }
  
  void update(){
     
     this.x = get_x();
     this.y = get_y();
     
     rad = min(width,height);

     this.radius = rad*sF;
  if(running)
    k++;
    
  }
  
  
}


/////////////////////////////////////////////////////

Cardioid c = new Cardioid(500,0);

void setup(){
  surface.setResizable(true);
  
  bgcolor = white;//black; //color(60,0,60);
  l_color = black;//darkred;//black;//lightblue;//crimson;//color(50,0,50);//red;
  

  
}

void settings(){
 
  size(windowWidth,windowHeight);
  
}

void draw(){
 
  background(bgcolor);
  c.draw();
 //if(frameCount % 5 == 0)

  c.update();
  
}
