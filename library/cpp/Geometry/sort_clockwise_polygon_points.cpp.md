---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
    title: test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/cpp/Geometry/sort_clockwise_polygon_points.cpp\"\
    \n#include <algorithm>\n#include <vector>\n\nstruct Point {\n    int x, y;\n};\n\
    \n// \u591A\u89D2\u5F62\u3092\u9023\u7D9A\u3059\u308B\u70B9\u306B\u3088\u3063\u3066\
    \u8868\u3057\u3066\u3044\u308B\u3068\u304D\uFF0C\n// \u5DE6\u4E0A(x\u304C\u6700\
    \u5C0F\u306E\u4E2D\u3067y\u304C\u6700\u5C0F\u306E\u3082\u306E)\u306E\u9802\u70B9\
    \u304B\u3089\u958B\u59CB\u3059\u308B\u53CD\u6642\u8A08\u56DE\u308A\u306E\u70B9\
    \u306B\u30BD\u30FC\u30C8\u3059\u308B\n// \u5168\u3066\u306E\u89D2\u304C 90 \u5EA6\
    \u307E\u305F\u306F 270 \u5EA6\u3067\u5358\u7D14\u3067\u3042\u308B\u3053\u3068\n\
    // \u5076\u6570\u756A\u76EE\u306F\u7E26\u7DDA\uFF0C\u5947\u6570\u756A\u76EE\u306F\
    \u6A2A\u7DDA\u306B\u306A\u308B\uFF0E(0-origin)\nvoid sort_clockwise_polygon_points(std::vector<Point>\
    \ &points) {\n    int left_up_idx = 0;\n    for (int i = 0; i < (int) points.size();\
    \ ++i) {\n        if (points[i].x < points[left_up_idx].x) {\n            left_up_idx\
    \ = i;\n        } else if (points[i].x == points[left_up_idx].x and points[i].y\
    \ > points[left_up_idx].y) {\n            left_up_idx = i;\n        }\n    }\n\
    \n    // left_up \u3092\u5148\u982D\u306B\u3082\u3063\u3066\u304F\u308B\n    std::rotate(points.begin(),\
    \ points.begin() + left_up_idx, points.end());\n\n    // points \u306E\u9806\u5E8F\
    \u304C\u6642\u8A08\u56DE\u308A\u306B\u306A\u3063\u3066\u3044\u308B\u5834\u5408\
    \uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B\u3059\u308B\n    if (points[0].x !=\
    \ points[1].x) {\n        std::reverse(points.begin() + 1, points.end());\n  \
    \  }\n}\n"
  code: "#include <algorithm>\n#include <vector>\n\nstruct Point {\n    int x, y;\n\
    };\n\n// \u591A\u89D2\u5F62\u3092\u9023\u7D9A\u3059\u308B\u70B9\u306B\u3088\u3063\
    \u3066\u8868\u3057\u3066\u3044\u308B\u3068\u304D\uFF0C\n// \u5DE6\u4E0A(x\u304C\
    \u6700\u5C0F\u306E\u4E2D\u3067y\u304C\u6700\u5C0F\u306E\u3082\u306E)\u306E\u9802\
    \u70B9\u304B\u3089\u958B\u59CB\u3059\u308B\u53CD\u6642\u8A08\u56DE\u308A\u306E\
    \u70B9\u306B\u30BD\u30FC\u30C8\u3059\u308B\n// \u5168\u3066\u306E\u89D2\u304C\
    \ 90 \u5EA6\u307E\u305F\u306F 270 \u5EA6\u3067\u5358\u7D14\u3067\u3042\u308B\u3053\
    \u3068\n// \u5076\u6570\u756A\u76EE\u306F\u7E26\u7DDA\uFF0C\u5947\u6570\u756A\u76EE\
    \u306F\u6A2A\u7DDA\u306B\u306A\u308B\uFF0E(0-origin)\nvoid sort_clockwise_polygon_points(std::vector<Point>\
    \ &points) {\n    int left_up_idx = 0;\n    for (int i = 0; i < (int) points.size();\
    \ ++i) {\n        if (points[i].x < points[left_up_idx].x) {\n            left_up_idx\
    \ = i;\n        } else if (points[i].x == points[left_up_idx].x and points[i].y\
    \ > points[left_up_idx].y) {\n            left_up_idx = i;\n        }\n    }\n\
    \n    // left_up \u3092\u5148\u982D\u306B\u3082\u3063\u3066\u304F\u308B\n    std::rotate(points.begin(),\
    \ points.begin() + left_up_idx, points.end());\n\n    // points \u306E\u9806\u5E8F\
    \u304C\u6642\u8A08\u56DE\u308A\u306B\u306A\u3063\u3066\u3044\u308B\u5834\u5408\
    \uFF0C\u53CD\u6642\u8A08\u56DE\u308A\u306B\u3059\u308B\n    if (points[0].x !=\
    \ points[1].x) {\n        std::reverse(points.begin() + 1, points.end());\n  \
    \  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/cpp/Geometry/sort_clockwise_polygon_points.cpp
  requiredBy: []
  timestamp: '2024-02-05 23:19:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/cpp/Geometry/sort_clockwise_polygon_points1.test.cpp
documentation_of: library/cpp/Geometry/sort_clockwise_polygon_points.cpp
layout: document
redirect_from:
- /library/library/cpp/Geometry/sort_clockwise_polygon_points.cpp
- /library/library/cpp/Geometry/sort_clockwise_polygon_points.cpp.html
title: library/cpp/Geometry/sort_clockwise_polygon_points.cpp
---
