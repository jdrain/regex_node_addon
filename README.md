Testing out cpp integration with node

**Installation**
```
git clone https://github.com/jdrain/regex_node_addon.git
```  

We need node-gyp to build node cpp addons

```
$npm install -g node-gyp
$node-gyp configure \
node-gyp build
```

**Run**
```
$node
> const re_match = require("./build/Release/regex_matching.node")
> re_match.regex_matching(<str>)
```
