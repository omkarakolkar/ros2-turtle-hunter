#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from my_robot_interfaces.msg import HardwareStatus
 
 
class HardwareStatusPublisher(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("hardwarestatuspublisher") # MODIFY NAME
        self.hw_status_publisher_ = self.create_publisher(HardwareStatus, "hardware_status", 10)
        self.time_ = self.create_timer(1.0, self.publish_hw_status)
        self.get_logger().info("Hardware status publisher has been started. ")

    def publish_hw_status(self):
        msg = HardwareStatus()
        msg.temperature = 45
        msg.are_motors_ready = True
        msg.debug_message = "Nothing special here"
        self.hw_status_publisher_.publish(msg)
 
 
def main(args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisher() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()
 
 
if __name__ == "__main__":
    main()