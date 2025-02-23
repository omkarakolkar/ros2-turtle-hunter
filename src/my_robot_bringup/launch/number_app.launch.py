from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    number_publisher_node = Node(

        package = "my_py_pkg",
        executable= "number_counter",
        name= "num_count", # renaming nodes
        remappings=[
            ("number", "my_number") #renaming topics and services
        ]
    )

    number_counter_node = Node(
        package = "my_cpp_pkg",
        executable= "number_publisher",

        parameters=[                    #setting parameters using launch files 
            {"number_to_publish": 4},
            {"publish_frequency": 1.3}
        ]
    )

    ld.add_action(number_publisher_node)
    ld.add_action(number_counter_node)
    return ld