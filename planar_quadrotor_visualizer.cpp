#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    int q_x, q_y, q_theta;
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];
    static double time = 0;
    time=time+0.00045;

    
    SDL_SetRenderDrawColor(gRenderer.get(), 0, 0, 0, 255);
    SDL_Rect obwod = {q_x-100, q_y-10, 204, 15};
    SDL_RenderFillRect(gRenderer.get(), &obwod);
    SDL_SetRenderDrawColor(gRenderer.get(), 60, 60, 60, 255);
    SDL_Rect srodek = {q_x-98, q_y-8, 200, 11};
    SDL_RenderFillRect(gRenderer.get(), &srodek);
    filledEllipseRGBA(gRenderer.get(), q_x-100, q_y-3, 5, 7, 60, 60, 60, 255);
    filledEllipseRGBA(gRenderer.get(), q_x+102, q_y-3, 5, 7, 60, 60, 60, 255);
    SDL_SetRenderDrawColor(gRenderer.get(), 0, 0, 0, 255);
    SDL_Rect palka_lewa = {q_x-65, q_y-28, 2, 18};
    SDL_RenderFillRect(gRenderer.get(), &palka_lewa);
    SDL_Rect palka_prawa = {q_x+65, q_y-28, 2, 18};
    SDL_RenderFillRect(gRenderer.get(), &palka_prawa);
    filledEllipseRGBA(gRenderer.get(), q_x-64, q_y-22, 28*(sin(15*time)+1), 3.5, 22, 178, 72, 255);
    filledEllipseRGBA(gRenderer.get(), q_x+66, q_y-22, 28*(sin(15*time)+1), 3.5, 22, 178, 72, 255);

}