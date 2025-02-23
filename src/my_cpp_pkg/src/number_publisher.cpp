#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class NumberPublisherNode : public rclcpp::Node
{
public:
    NumberPublisherNode() : Node("number_publisher")
    {
        // Declare parameters with default values
        this->declare_parameter<int>("number_to_publish", 0);
        this->declare_parameter<double>("publish_frequency", 1.0);

        // Get parameter values
        number_ = this->get_parameter("number_to_publish").as_int();
        publish_frequency_ = this->get_parameter("publish_frequency").as_double();

        // Create publisher
        number_publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number", 10);

        // Create timer based on the publish frequency
        timer_ = this->create_wall_timer(std::chrono::milliseconds((int) (1000.0 / publish_frequency_)),
                                        std::bind(&NumberPublisherNode::publish_number, this));

        RCLCPP_INFO(this->get_logger(), "Number Publisher has started.");
    }

private:
    void publish_number()
    {
        auto msg = example_interfaces::msg::Int64();
        msg.data = number_;
        number_publisher_->publish(msg);
    }

    int number_;
    double publish_frequency_;
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr number_publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<NumberPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
