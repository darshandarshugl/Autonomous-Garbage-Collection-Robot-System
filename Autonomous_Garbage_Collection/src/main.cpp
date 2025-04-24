

#include "../include/mario_com/RobotSim.hpp"
#include <rclcpp/utilities.hpp>
int main(int argc, char * argv[]) {
    // Initialize the ROS
    rclcpp::init(argc, argv);
    // Create Robot Simulator Object
    RobotSim rs;
    // Start the operation
    RCLCPP_INFO(rclcpp::get_logger("log"), "Starting Trash Collection");
    while (!rs.m_nav.search_bins()) {
        if (rs.m_perc.detect_bin()) {
            break;
        }
    }
    rclcpp::sleep_for(2s);
    rs.m_manip.pick_bin();
    rs.m_nav.move_to_disposal_zone();
    rs.m_manip.place_bin();
    rs.m_nav.resume_search();
    // Shutdown ROS
    rclcpp::shutdown();
    // cv::destroyWindow("view");
    return 0;
}
