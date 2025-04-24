
#pragma once
#include "rclcpp/rclcpp.hpp"
#include "./Manipulation.hpp"
#include "./Navigation.hpp"
#include "./Perception.hpp"

/**
 * @brief RobotSim class to simulate the medical disposal task of the robot.
 * 
 */
class RobotSim {
 public:
    /**
    * @brief Construct a new Robot Sim object
    * 
    */
    RobotSim();

    Navigation m_nav;
    Perception m_perc;
    Manipulation m_manip;
};
