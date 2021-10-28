#ifndef _WEB_STRINGS_H_
#define _WEB_STRINGS_H_
const char index_html[] PROGMEM = "<html lang='en'>"
  "<head>"
    "<meta name='format-detection' content='telephone=no'>"
    "<meta charset='UTF-8'><meta name='viewport' content='width=device-width,initial-scale=1,user-scalable=no'>"
    "<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>"
    "<script src='https://code.jquery.com/jquery-3.2.1.slim.min.js' integrity='sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN' crossorigin='anonymous'></script>"
    "<script src='https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js' integrity='sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q' crossorigin='anonymous'></script>"
    "<script src='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js' integrity='sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl' crossorigin='anonymous'></script>"
    "<link rel='preconnect' href='https://fonts.googleapis.com'><link rel='preconnect' href='https://fonts.gstatic.com' crossorigin=''>"
    "<link href='https://fonts.googleapis.com/css2?family=MuseoModerno:wght@500&amp;display=swap' rel='stylesheet'>"
    "<title>HODLcube Settings</title>"

    "<script>"
      "$(document).ready(function () {"
        "$('#checkBoxAlert, #submitAlert').hide();"
        "$('#settingsForm').submit(function (event) {"
          "if ($('input.pair-checkbox:checked').length > 0) {"
            "$('#submitAlert').show();"
            "setTimeout(location.reload.bind(location), 5000);"
          "} else {"
            "$('#checkBoxAlert').show();"
            "event.preventDefault();"
          "}"
        "});"
        "var limit = 5;"
        "$('input.pair-checkbox').on('change', function (evt) {"
          "if ($('input.pair-checkbox:checked').length > limit) {"
            "this.checked = false;"
            "$('#checkBoxAlert').show();"
          "} else {"
            "$('#checkBoxAlert').hide();"
          "}"
        "});"
      "});"
    "</script>"
  "</head>"
  "<body>"
    "<header class='flex-column flex-md-row navbar' style='background-color: #4d4d4e;color: #ffffff;'>"
      "<span style=""font-family: 'MuseoModerno', cursive;"">HODLcube Settings</span>"
    "</header>"
    "<div class='container'>"
      "<h4>Price change thresholds<a class='font-weight-bold' data-toggle='collapse' href='#collapseThresholds' aria-expanded='false' aria-controls='collapseThresholds'> ?</a></h4>"
      "<div class='collapse' id='collapseThresholds'>"
        "<div class='mb-2 alert alert-info'>Thresholds affect sesitivity of LEDs and buzzer to price change. Price change means difference between two displayed prices of the same currency pair in a "
          "row in case of ticker or difference between checkpoint value and current price in case of long term watcher. The lower the <a href='#screenChangeDelay'>screen change delay</a>, the smaller the price "
          "difference and the lower the threshold (higher sensitivity) needed to activate LEDs or buzzer.</div>"
      "</div>"
      "<form action='/get' target='hidden-form' id='settingsForm'>"
        "<h5>Price ticker</h5>"
        "<div class='mb-2'>"
          "<label for='inputLEDtickThresh' class='col-form-label'>LEDs (percent)"
            "<a class='font-weight-bold' data-toggle='collapse' href='#collapseHelpLED' aria-expanded='false' aria-controls='collapseHelpLED'> ?</a>"
          "</label>"
          "<div class='mb-2'>"
            "<input type='number' name='inputLEDtickThresh' step='0.01' min='0' max='100' value='%inputLEDtickThresh%' class='form-control' required>"
          "</div>"
        "</div>"
        "<div class='collapse' id='collapseHelpLED'>"
          "<div class='mb-2 alert alert-info'>This value has to be between 0 (highest price change sensitivity) and 100 (turned off).<hr>"
            "<p class='mb-0'>Example: current price 1&nbsp;000, threshold 0.01; 1&nbsp;000*(0.01/100)=0.1. LED flashes when price decreases (red) or increases (green) by 0.1 to 999.9 and 1000.1 respectively.</p>"
          "</div>"
        "</div>"
        "<div class='mb-2'>"
          "<label for='inputBuzzTickThresh' class='col-form-label'>Buzzer (percent)"
            "<a class='font-weight-bold' data-toggle='collapse' href='#collapseHelpBuzzTickThresh' aria-expanded='false' aria-controls='collapseHelpBuzzTickThresh'> ?</a>"
          "</label>"
          "<div class='mb-2'>"
            "<input type='number' name='inputBuzzTickThresh' step='0.01' min='0' max='100' value='%inputBuzzTickThresh%' class='form-control' required>"
          "</div>"
        "</div>"
        "<div class='collapse' id='collapseHelpBuzzTickThresh'>"
          "<div class='mb-2 alert alert-info'>This value has to be between 0 (highest price change sensitivity) and 100 (turned off).<hr>"
            "<p class='mb-0'>Example: current price 45&nbsp;000, threshold 0.5; 45&nbsp;000*(0.5/100)=225. Buzzer sounds when price changes by 225, to 44&nbsp;775 or 45&nbsp;225</p>"
          "</div>"
        "</div>"
        "<h5>Long term price watcher</h5>"
        "<div class='mb-2'>"
          "<label for='inputBuzzCPThresh' class='col-form-label'>Buzzer (percent)"
            "<a class='font-weight-bold' data-toggle='collapse' href='#collapseHelpBuzzCPThresh' aria-expanded='false' aria-controls='collapseHelpBuzzCPThresh'> ?</a>"
          "</label>"
          "<div class='mb-2'>"
            "<input type='number' name='inputBuzzCPThresh' step='0.1' min='0.1' value='%inputBuzzCPThresh%' class='form-control' required>"
          "</div>"
        "</div>"
        "<div class='collapse' id='collapseHelpBuzzCPThresh'>"
          "<div class='mb-2 alert alert-info'>This value has to be higher or equal to 0.1. When checkpoint value and current price differs by specified number of percent, "
            "buzzer is activated. Initial checkpoint value for each currency pair is equal to first displayed price after device startup. When the threshold is reached, the new "
            "checkpoint is also created. Current price checkpoints are displayed near relevant <a href='#currencyPairs'>currency pairs</a> below.<hr>"
            "<p class='mb-0'>Example: checkpoint 50&nbsp;000, threshold 5; 50&nbsp;000*(5/100)=2500. When price 52&nbsp;500 or 47&nbsp;500 is reached, "
            "a buzzer sounds and a new checkpoint with the current value is also created.</p>"
          "</div>"
        "</div>"
        "<div class='mb-2'>"
          "<div class='mb-2 alert alert-info'>The higher the threshold values, the less often the LEDs (buzzer) activated."
          "</div>"
        "</div>"
        "<h4 id='currencyPairs'>Currency pairs (limit is 5)</h4>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair0' value='btc-usd' %btc-usd%>"
          "<label for='pair0' class='form-check-label'>Bitcoin - US Dollar</label>"
          "%currCheckpoint_btc-usd%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair1' value='btc-eur' %btc-eur%>"
          "<label for='pair1' class='form-check-label'>Bitcoin - Euro</label>"
          "%currCheckpoint_btc-eur%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair2' value='btc-gbp' %btc-gbp%>"
          "<label for='pair2' class='form-check-label'>Bitcoin - British Pound</label>"
          "%currCheckpoint_btc-gbp%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair3' value='eth-btc' %eth-btc%>"
          "<label for='pair3' class='form-check-label'>Ethereum - Bitcoin</label>"
          "%currCheckpoint_eth-btc%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair4' value='eth-usd' %eth-usd%>"
          "<label for='pair4' class='form-check-label'>Ethereum - US Dollar</label>"
          "%currCheckpoint_eth-usd%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair5' value='eth-eur' %eth-eur%>"
          "<label for='pair5' class='form-check-label'>Ethereum - Euro</label>"
          "%currCheckpoint_eth-eur%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair6' value='eth-gbp' %eth-gbp%>"
          "<label for='pair6' class='form-check-label'>Ethereum - British Pound</label>"
          "%currCheckpoint_eth-gbp%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair7' value='ltc-usd' %ltc-usd%>"
          "<label for='pair7' class='form-check-label'>Litecoin - US Dollar</label>"
          "%currCheckpoint_ltc-usd%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair8' value='ltc-eur' %ltc-eur%>"
          "<label for='pair8' class='form-check-label'>Litecoin - Euro</label>"
          "%currCheckpoint_ltc-eur%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair9' value='ltc-gbp' %ltc-gbp%>"
          "<label for='pair9' class='form-check-label'>Litecoin - British Pound</label>"
          "%currCheckpoint_ltc-gbp%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair10' value='ada-usd' %ada-usd%>"
          "<label for='pair10' class='form-check-label'>Cardano - US Dollar</label>"
          "%currCheckpoint_ada-usd%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair11' value='ada-eur' %ada-eur%>"
          "<label for='pair11' class='form-check-label'>Cardano - Euro</label>"
          "%currCheckpoint_ada-eur%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair12' value='ada-gbp' %ada-gbp%>"
          "<label for='pair12' class='form-check-label'>Cardano - British Pound</label>"
          "%currCheckpoint_ada-gbp%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair13' value='sol-usd' %sol-usd%>"
          "<label for='crypt13' class='form-check-label'>Solana - US Dollar</label>"
          "%currCheckpoint_sol-usd%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair14' value='sol-eur' %sol-eur%>"
          "<label for='pair14' class='form-check-label'>Solana - Euro</label>"
          "%currCheckpoint_sol-eur%"
        "</div>"
        "<div class='form-check'>"
          "<input class='pair-checkbox form-check-input' type='checkbox' name='pair15' value='sol-gbp' %sol-gbp%>"
          "<label for='pair15' class='form-check-label'>Solana - British Pound</label>"
          "%currCheckpoint_sol-gbp%"
        "</div>"
        "<div id='checkBoxAlert' class='invalid-feedback'>Select from 1 to 5 currency pairs</div>"
        "<h4>Screen</h4>"
        "<div class='mb-2' id='screenChangeDelay'>"
          "<label for='inputScreenChangeDelay' class='col-form-label'>Screen change delay</label>"
          "<div class='mb-2'>"
            "<select name='inputScreenChangeDelay' class='form-control'>"
              "<option value='2000' %screenChangeDelay2000%>2s</option>"
              "<option value='5000' %screenChangeDelay5000%>5s</option>"
              "<option value='10000' %screenChangeDelay10000%>10s</option>"
              "<option value='60000' %screenChangeDelay60000%>60s</option>"
              "<option value='300000' %screenChangeDelay300000%>5m</option>"
            "</select>"
          "</div>"
        "</div>"
        "<div id='submitAlert' class='alert alert-success'>"
          "Settings saved. HODLcube will restart in few seconds."
        "</div>"
        "<button type='submit' class='btn btn-primary mb-2'>Save</button>"
      "</form>"
      "<iframe style='display:none' name='hidden-form'></iframe>"
    "</div>"
  "</body>"
"</html>";

#endif
