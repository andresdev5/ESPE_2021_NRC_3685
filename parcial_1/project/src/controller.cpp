#include "controller.h"

Controller::Controller(Application *app) : app_(app) {}

Application *Controller::app() {
    return app_;
}
