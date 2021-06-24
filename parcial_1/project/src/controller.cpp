#include "controller.h"

Controller::Controller(Application *app) : app_(app) {}

Application *Controller::get_app() {
    return app_;
}
