#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"

class MappingNode : public rclcpp::Node {
public:
  MappingNode() : Node("mapping_node") {
    subscription_ = create_subscription<sensor_msgs::msg::LaserScan>(
        "laser_scan_topic", 10, std::bind(&MappingNode::scan_callback, this, std::placeholders::_1));
    publisher_ = create_publisher<nav_msgs::msg::OccupancyGrid>("map_topic", 10);
  }

private:
  void scan_callback(const sensor_msgs::msg::LaserScan::SharedPtr msg) {
    // Process the laser scan data and update the map
    // Implement SLAM algorithms or use existing packages like gmapping

    // Publish the updated map
    auto map_msg = std::make_unique<nav_msgs::msg::OccupancyGrid>();
    // Popular
for slam mapping ;
