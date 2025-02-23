from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    ld = LaunchDescription()

    robot_names = ["Giskard", "C3PO", "Chitti", "FigureOne", "TeslaBot"]
    
    robot_news_station_nodes=[]

    for name in robot_names:
        robot_news_station_nodes.append(Node(
            package = "my_py_pkg",
            executable= "robot_news_station",
            name= "rns_" + name.lower(), # renaming nodes
            parameters=[
                {"robot_name": name}
            ])
        )

    smartphone= Node(
        package="my_py_pkg",
        executable="smartphone",
        name="smartphone"
    )

    for node in robot_news_station_nodes:
        ld.add_action(node)
    ld.add_action(smartphone)
    return ld