#include "gear2d.h"

using namespace gear2d;

class logo : public component::base {
  public:
    virtual void setup(object::signature & sig);
    virtual component::type type() { return "logo"; }
    virtual std::string depends() { return "renderer/renderer2 mouse/mouse"; }
    virtual void update(timediff dt, int begin);
    
    
  private:
    bool finished;
    bool quitted;
    gear2d::link<float> facealpha;
    gear2d::link<int> mouse1;
};

void logo::setup(object::signature & sig) {
  finished = false;
  quitted = false;
  facealpha = fetch("face.alpha", 0.0f);
  mouse1 = fetch<int>("mouse.1");
}

void logo::update(timediff dt, int begin) {
  if (!finished) facealpha += 2 * dt;
  if (facealpha >= 1.0f) {
    finished = true;
    facealpha = 1.0f;
  }
  if (mouse1 == 1 && !quitted) {
    modinfo("logo");
    trace("mouse1", mouse1);
    engine::quit();
    quitted = true;
  }
}


g2dcomponent(logo, logo, logo)