#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MyProcessor : public rclcpp::Nod {
public:
    MyProcessor() : Node("my_processor_node") {
        // Create a subscriber for the "input_topic"
        subscriber_ = this->create_subscription<std_msgs::msg::String>(
            "input_topic", 10, [this](const std_msgs::msg::String::SharedPtr msg) {
                processMessage(msg);
            });

        // Create a publisher for the "output_topic"
        publisher_ = this->create_publisher<std_msgs::msg::String>("output_topic", 10);
    }

private:
    void processMessage(const std_msgs::msg::String::SharedPtr msg) {
        // Perform some processing on the received message
        auto processed_msg = std_msgs::msg::String();
        processed_msg.data = "Processed: " + msg->data;

        RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
        RCLCPP_INFO(this->get_logger(), "Processed: '%s'", processed_msg.data.c_str());

        // Publish the processed message
        publisher_->publish(processed_msg);
    }

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
};

int main(int argc, char** argv) {
    // Initialize the ROS 2 system
    rclcpp::init(argc, argv);

    // Create a node and run it
    auto node = std::make_shared<MyProcessor>();
    rclcpp::spin(node);

    // Shutdown the ROS 2 system
    rclcpp::shutdown();

    return 0;
}
