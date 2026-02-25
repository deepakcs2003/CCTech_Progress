type direction="up"|"down"|"left"|"right"
let mode:direction;
mode="up"
// mode="forward"

type DiceRoll=1|2|3|4|5|6
function rollDice():DiceRoll{
    return 4;
    // return 7;
}
console.log(rollDice());

type Success=true;
function operation():Success{
    return true;
    // return false;
}

console.log(operation());