var Direction;
(function (Direction) {
    Direction["up"] = "upper";
    Direction["down"] = "niche";
    Direction[Direction["left"] = 3] = "left";
    Direction[Direction["right"] = 6] = "right";
})(Direction || (Direction = {}));
var move = Direction.up;
console.log(move);
