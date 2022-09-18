
/**
 * @param {number[][]} properties
 * @return {number}
 */
var numberOfWeakCharacters = function (properties) {

    properties.sort((x, y) => (x[0] === y[0]) ? (y[1] - x[1]) : (x[0] - y[0]));
    let maxDefence = properties[properties.length - 1][1];
    let countNumberOfWeakCharacters = 0;

    for (let i = properties.length - 2; i >= 0; --i) {
        countNumberOfWeakCharacters += (properties[i][1] < maxDefence) ? 1 : 0;
        maxDefence = Math.max(maxDefence, properties[i][1]);
    }
    return countNumberOfWeakCharacters;
};
