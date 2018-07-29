function solution(N, relation, dirname) {
    var answer = 0;
    var nodes = [];

    function Node(index, dirname) {
        this.index = index;
        this.children = [];
        this.dirname = dirname;
    }

    Node.prototype.setParent = function (node) {
        this.parent = node;
    }

    Node.prototype.addChildren = function (node) {
        this.children.push(node);
    }

    for (let i = 0; i < dirname.length; i++) {
        nodes[i] = new Node(i, dirname[i]);
    }

    for (let i = 0; i < relation.length; i++) {
        const [parentIdx, childIdx] = relation[i];
        const parentNode = nodes[parentIdx - 1];
        const childNode = nodes[childIdx - 1];

        parentNode.addChildren(childNode);
        childNode.setParent(parentNode);
    }

    const traverse = node => {
        let largestChildPath = 0;

        if (node.children.length < 1) {
            return node.dirname.length;
        }

        for(let i = 0; i < node.children.length; i++) {
            largestChildPath = Math.max(largestChildPath, traverse(node.children[i]));
        }

        return node.dirname.length + 1 + largestChildPath;
    }

    return traverse(nodes[0]);
}