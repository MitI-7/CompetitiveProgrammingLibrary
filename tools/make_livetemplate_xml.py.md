---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import os\nimport pathlib\nimport xml.etree.ElementTree as ET\n\n\ndef make_live_template(input_directory:\
    \ pathlib.Path, output_directory=pathlib.Path(\"templates\")):\n    if not output_directory.exists():\n\
    \        os.mkdir(output_directory)\n\n    for group_directory in input_directory.iterdir():\n\
    \        group = group_directory.name\n        print(group)\n        \n      \
    \  root = ET.Element(\"templateSet\")\n        root.set(\"group\", group)\n\n\
    \        for snippet_file in group_directory.iterdir():\n            print(f\"\
    * {snippet_file.name}\")\n            name = snippet_file.name.split(\".\")[0]\n\
    \            description = name\n\n            value = \"\"\n            with\
    \ snippet_file.open(encoding=\"utf-8\") as f:\n                for line in f:\n\
    \                    if '#' == line[0]:\n                        line = \"//\"\
    \ + line\n                    value += line\n\n            template = ET.SubElement(root,\
    \ \"template\")\n            template.set(\"name\", name)\n            template.set(\"\
    value\", value)\n            template.set(\"description\", description)\n    \
    \        template.set(\"toReformat\", \"false\")\n            template.set(\"\
    toShortenFQNames\", \"true\")\n\n            context = ET.SubElement(template,\
    \ \"context\")\n            option = ET.SubElement(context, \"option\")\n    \
    \        option.set(\"name\", \"cpp\")\n            option.set(\"value\", \"true\"\
    )\n\n        tree = ET.ElementTree(element=root)\n        tree.write(os.path.join(output_directory,\
    \ f\"{group}.xml\"), encoding=\"utf-8\", xml_declaration=False)\n\n\ndef main():\n\
    \    input_directory = pathlib.Path(\"../library/cpp\")\n    make_live_template(input_directory=input_directory)\n\
    \n\nif __name__ == '__main__':\n    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: tools/make_livetemplate_xml.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tools/make_livetemplate_xml.py
layout: document
redirect_from:
- /library/tools/make_livetemplate_xml.py
- /library/tools/make_livetemplate_xml.py.html
title: tools/make_livetemplate_xml.py
---
