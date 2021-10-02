exports.replaceNewline = function(input) {
  var newline = String.fromCharCode(13, 10);
  return input.replaceAll('\\n', newline);
}