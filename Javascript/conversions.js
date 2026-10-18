export function Bytes_to_KB(byte) {
  if (typeof byte !== "number" || byte < 0) {
    console.error("Invalid figure!");
    return;
  }
  //convert
  const result = byte / 2 ** 10;

  //return
  return result;
}

export function Bytes_to_MB(byte) {
  if (typeof byte !== "number" || byte < 0) {
    console.error("Invalid figure!");
    return;
  }

  const result = Number((byte / 2 ** 20).toFixed(3));
  return result;
}

export function Bytes_to_GB(byte) {
  if (typeof byte !== "number" || byte < 0) {
    console.error("Invalid figure!");
    return;
  }
  const result = Number((byte / 2 ** 30).toFixed(3));
  return result;
}
