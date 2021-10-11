import React from "react";

const Alert = ({ alert }) => {
  const capitalize = (string) => {
    return string.charAt(0).toUpperCase() + string.slice(1);
  };
  return (
    <div style={{ height: "50px" }}>
      {alert && (
        <div
          className={`alert alert-${alert.type} alert-dismissible`}
          role="alert"
          id="liveAlert"
        >
          <strong>{capitalize(alert.type)}</strong> ! {alert.message}
        </div>
      )}
    </div>
  );
};


export default Alert;
