import os
import pathlib
import xml.etree.ElementTree as ET


def make_live_template(input_directory: pathlib.Path, output_directory=pathlib.Path("templates")):
    if not output_directory.exists():
        os.mkdir(output_directory)

    for group_directory in input_directory.iterdir():
        group = group_directory.name
        print(group)
        
        root = ET.Element("templateSet")
        root.set("group", group)

        for snippet_file in group_directory.iterdir():
            print(f"* {snippet_file.name}")
            name = snippet_file.name.split(".")[0]
            description = name

            value = ""
            with snippet_file.open(encoding="utf-8") as f:
                for line in f:
                    if '#' == line[0]:
                        line = "//" + line
                    value += line

            template = ET.SubElement(root, "template")
            template.set("name", name)
            template.set("value", value)
            template.set("description", description)
            template.set("toReformat", "false")
            template.set("toShortenFQNames", "true")

            context = ET.SubElement(template, "context")
            option = ET.SubElement(context, "option")
            option.set("name", "cpp")
            option.set("value", "true")

        tree = ET.ElementTree(element=root)
        tree.write(os.path.join(output_directory, f"{group}.xml"), encoding="utf-8", xml_declaration=False)


def main():
    input_directory = pathlib.Path("../library/cpp")
    make_live_template(input_directory=input_directory)


if __name__ == '__main__':
    main()
