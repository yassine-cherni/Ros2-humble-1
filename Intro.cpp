#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MyPublisher : public rclcpp::Node {
public:
    MyPublisher() : Node("my_publisher_node") {
        // Create a publisher on the "my_topic" topic with a queue size of 10
        publisher_ = this->create_publisher<std_msgs::msg::String>("my_topic", 10);

        // Set up a timer to publish a message every second
        timer_ = this->create_wall_timer(std::chrono::seconds(1), [this]() {
            auto message = std_msgs::msg::String();
            message.data = "Hello, ROS 2!";
            RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
            publisher_->publish(message);
        });
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
    // Initialize the ROS 2 system
    rclcpp::init(argc, argv);

    // Create a node and run it
    auto node = std::make_shared<MyPublisher>();
    rclcpp::spin(node);

    // Shutdown the ROS 2 system
    rclcpp::shutdown();

    return ;
}
