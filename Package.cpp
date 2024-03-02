#include "rclcpp/rclcpp.hpp"

class Talker : public rclcpp::Node
{
public:
    Talker()
    : Node("talker")
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);
        timer_ = this->create_wall_timer(
            500ms, std::bind(&Talker::timer_callback, this));
    }

priva
    void timer_callback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, World!";
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
        publisher_->publish(message);
    }
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Talker>());
    rclcpp::shutdown();
    return 0;
}
