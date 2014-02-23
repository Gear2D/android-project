#include "gear2d.h"
#include <string>

using namespace gear2d;

class logo : public component::base {
  public:
    virtual void setup(object::signature & sig);
    virtual component::type type() { return "logo"; }
    virtual std::string depends() { return "renderer/renderer2 kinematics/kinematic2d mouse/mouse touch/touch"; }
    virtual void update(timediff dt, int begin);
    virtual void handle(parameterbase::id pid, base * lastwrite, object::id owner);    
    
  private:
    bool finished;
    bool quitted;
    gear2d::link<float> facealpha;
    gear2d::link<int> mouse1;
    gear2d::link<int> gearw;
    gear2d::link<int> gearh;
    gear2d::link<int> gearx;
    gear2d::link<int> geary;
    
    struct {
      gear2d::link<float> x, y, w, h;
      float basew, baseh;
    } camera;
    
    int ow,  oh, ox;
    
};

void logo::handle(parameterbase::id pid, component::base * lastwrite, object::id owner) {
}


void logo::setup(object::signature & sig) {
  finished = false;
  quitted = false;
  facealpha = fetch("face.alpha", 0.0f);
  mouse1 = fetch<int>("mouse.1");
  gearw = fetch<int>("gear.w");
  gearh = fetch<int>("gear.h");
  gearx = fetch<int>("gear.x");
  camera = { globals.fetch<float>("camera.x"), globals.fetch<float>("camera.y"), globals.fetch<float>("camera.w"), globals.fetch<float>("camera.h") };
  camera.basew = camera.w; camera.baseh = camera.h;
  ow = gearw;
  oh = gearh;
  ox = gearx;
}

void logo::update(timediff dt, int begin) {
  /*
  if (!finished) facealpha += 2 * dt;
  if (facealpha >= 1.0f) {
    finished = true;
    facealpha = 1.0f;
  }
  */
  float tx = read<float>("touch.0.x") * read<int>("render.w");
  float ty = read<float>("touch.0.y") * read<int>("render.h");
  
  float cx = read<int>("x") + read<int>("render.w") / 2;
  float cy = read<int>("y") + read<int>("render.y") / 2;

  if (read<int>("touch.0") == 0) {
    tx = cx;
    ty = cy;
  }
  //write("x.speed", tx - cx);
  //write("y.speed", ty - cy);
  
  facealpha = facealpha * 0.9 + (0.1 * read<float>("touch.0.pressure"));
  if (facealpha > 1) facealpha = 1.0f;
  static char buf[255];
  int m =read<int>("mouse.1");

  if (m == 1) {
    modinfo("logo");
    float x = read<int>("mouse.x");
    float y = read<int>("mouse.y");
    trace("Got a click in", x, y, "in camera. Actual camera is", camera.x, camera.y);
    camera.w = camera.w/2;
    camera.h = camera.h/2;
    camera.x = (camera.x + x) - camera.w/2;
    camera.y = (camera.y + y) - camera.h/2;

    trace("Camera set to", camera.x, camera.y);
    //camera.y = y;
  } else if (m == 3) {
    camera.w = camera.basew;
    camera.h = camera.baseh;
    camera.x = 0;
    camera.y = 0;
  }
  
    
  float p = read<float>("touch.0.pressure");
  //sprintf(buf, "%f", p);
  //write<std::string>("test.text", buf);  
  
  gearw = ow * (1+ p);
  gearx = ox - (ow - gearw) / 2.0f;
  //camera.x = tx;
  //camera.y = ty;
  //camera.w = (1-p) * camera.basew;
  //camera.h = (1-p) * camera.baseh;

  //trace(ow, oh, gearw, gearh);
}


g2dcomponent(logo, logo, logo)
