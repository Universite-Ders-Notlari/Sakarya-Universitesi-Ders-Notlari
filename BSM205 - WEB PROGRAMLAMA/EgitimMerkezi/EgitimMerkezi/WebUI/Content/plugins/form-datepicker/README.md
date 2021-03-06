# [bootstrap-datepicker](http://eternicode.github.com/bootstrap-datepicker/) [![Build Status](https://travis-ci.org/eternicode/bootstrap-datepicker.png?branch=master)](https://travis-ci.org/eternicode/bootstrap-datepicker)

This is a fork of Stefan Petre's [original code](http://www.eyecon.ro/bootstrap-datepicker/);
thanks go to him for getting this thing started!

Please note that this fork is not used on Stefan's page at this time, nor is it maintained or
contributed to by him (yet?)

Versions are incremented according to [semver](http://semver.org/).

# Requirements

* [Bootstrap](http://twitter.github.com/bootstrap/) 2.0.4+
* [jQuery](http://jquery.com/) 1.7.1+

These are the specific versions bootstrap-datpicker is tested against (`js` files) and built against (`css` files).  Use other versions at your own risk.

# Example

Attached to a field with the format specified via options:

```html
<input type="text" value="02-16-2012" class="datepicker">
```
```javascript
$('.datepicker').datepicker({
    format: 'mm-dd-yyyy'
});
```

Attached to a field with the format specified via data tag:

```html
<input type="text" value="02/16/12" data-date-format="mm/dd/yy" class="datepicker" >
```
```javascript
$('.datepicker').datepicker();
```

As component:

```html
<div class="input-append date datepicker" data-date="12-02-2012" data-date-format="dd-mm-yyyy">
    <input size="16" type="text" value="12-02-2012" readonly><span class="add-on"><i class="fa fa-th"></i></span>
</div>
```
```javascript
$('.datepicker').datepicker();
```

Attached to non-field element, using events to work with the date values.

```html
<div class="alert alert-error" id="alert">
    <strong>Oh snap!</strong>
</div>
<table class="table">
    <thead>
        <tr>
          <th>
              Start date
              <a href="#" class="btn small" id="date-start" data-date-format="yyyy-mm-dd" data-date="2012-02-20">Change</a>
          </th>
          <th>
              End date
              <a href="#" class="btn small" id="date-end" data-date-format="yyyy-mm-dd" data-date="2012-02-25">Change</a>
          </th>
        </tr>
    </thead>
    <tbody>
        <tr>
          <td id="date-start-display">2012-02-20</td>
          <td id="date-end-display">2012-02-25</td>
        </tr>
    </tbody>
</table>
```
```javascript
var startDate = new Date(2012,1,20);
var endDate = new Date(2012,1,25);
$('#date-start')
    .datepicker()
    .on('changeDate', function(ev){
        if (ev.date.valueOf() > endDate.valueOf()){
            $('#alert').show().find('strong').text('The start date must be before the end date.');
        } else {
            $('#alert').hide();
            startDate = new Date(ev.date);
            $('#date-start-display').text($('#date-start').data('date'));
        }
        $('#date-start').datepicker('hide');
    });
$('#date-end')
    .datepicker()
    .on('changeDate', function(ev){
        if (ev.date.valueOf() < startDate.valueOf()){
            $('#alert').show().find('strong').text('The end date must be after the start date.');
        } else {
            $('#alert').hide();
            endDate = new Date(ev.date);
            $('#date-end-display').text($('#date-end').data('date'));
        }
        $('#date-end').datepicker('hide');
    });
```

As inline datepicker:

```html
<div class="datepicker"></div>
```
```javascript
$('.datepicker').datepicker();
```


# Using bootstrap-datepicker.js

Call the datepicker via javascript:

```javascript
$('.datepicker').datepicker()
```

## Dependencies

Requires bootstrap's dropdown component (`dropdowns.less`) for some styles, and bootstrap's sprites (`sprites.less` and associated images) for arrows.

A standalone .css file (including necessary dropdown styles and alternative, text-based arrows) can be generated by running `build/build_standalone.less` through the `lessc` compiler:

```bash
$ lessc build/build_standalone.less datepicker.css
```

## Options

All options that take a "Date" can handle a `Date` object; a String formatted according to the given `format`; or a timedelta relative to today, eg '-1d', '+6m +1y', etc, where valid units are 'd' (day), 'w' (week), 'm' (month), and 'y' (year).

### format

String.  Default: 'mm/dd/yyyy'

The date format, combination of d, dd, D, DD, m, mm, M, MM, yy, yyyy.

* d, dd: Numeric date, no leading zero and leading zero, respectively.  Eg, 5, 05.
* D, DD: Abbreviated and full weekday names, respectively.  Eg, Mon, Monday.
* m, mm: Numeric month, no leading zero and leading zero, respectively.  Eg, 7, 07.
* M, MM: Abbreviated and full month names, respectively.  Eg, Jan, January
* yy, yyyy: 2- and 4-digit years, respectively.  Eg, 12, 2012.

### weekStart

Integer.  Default: 0

Day of the week start. 0 (Sunday) to 6 (Saturday)

### calendarWeeks

Boolean. Default: false

Whether or not to show week numbers to the left of week rows.

### startDate

Date.  Default: Beginning of time

The earliest date that may be selected; all earlier dates will be disabled.

### endDate

Date.  Default: End of time

The latest date that may be selected; all later dates will be disabled.

### daysOfWeekDisabled

String, Array.  Default: '', []

Days of the week that should be disabled. Values are 0 (Sunday) to 6 (Saturday). Multiple values should be comma-separated. Example: disable weekends: `'0,6'` or `[0,6]`.

### autoclose

Boolean.  Default: false

Whether or not to close the datepicker immediately when a date is selected.

### startView

Number, String.  Default: 0, 'month'

The view that the datepicker should show when it is opened.  Accepts values of 0 or 'month' for month view (the default), 1 or 'year' for the 12-month overview, and 2 or 'decade' for the 10-year overview.  Useful for date-of-birth datepickers.

### minViewMode

Number, String.  Default: 0, 'days'

Set a limit for the view mode.  Accepts: 'days' or 0, 'months' or 1, and 'years' or 2.
Gives the ability to pick only a month or an year.  The day is set to the 1st for 'months', and the month is set to January for 'years'.

### todayBtn

Boolean, "linked".  Default: false

If true or "linked", displays a "Today" button at the bottom of the datepicker to select the current date.  If true, the "Today" button will only move the current date into view; if "linked", the current date will also be selected.

### todayHighlight

Boolean.  Default: false

If true, highlights the current date.

### keyboardNavigation

Boolean.  Default: true

Whether or not to allow date navigation by arrow keys.

### language

String.  Default: 'en'

The IETF code (eg  "en" for English, "pt-BR" for Brazilian Portuguese) of the language to use for month and day names.  These will also be used as the input's value (and subsequently sent to the server in the case of form submissions).  If a full code (eg "de-DE") is supplied the picker will first check for an "de-DE" language and if not found will fallback and check for a "de" language.  If an unknown language code is given, English will be used.  See I18N below.

### forceParse

Boolean.  Default: true

Whether or not to force parsing of the input value when the picker is closed.  That is, when an invalid date is left in the input field by the user, the picker will forcibly parse that value, and set the input's value to the new, valid date, conforming to the given `format`.

## Markup

Format a component.

```html
<div class="input-append date datepicker" data-date="12-02-2012" data-date-format="dd-mm-yyyy">
    <input class="span2" size="16" type="text" value="12-02-2012"><span class="add-on"><i class="fa fa-th"></i></span>
</div>
```

## Methods

### .datepicker(options)

Initializes an datepicker.

### remove

Arguments: None

Remove the datepicker.  Removes attached events, internal attached objects, and
added HTML elements.

```javascript
$('.datepicker').datepicker('remove');
```

### show

Arguments: None

Show the datepicker.

```javascript
$('.datepicker').datepicker('show');
```

### hide

Arguments: None

Hide the datepicker.

```javascript
$('.datepicker').datepicker('hide');
```

### update

Arguments:

* date (String|Date)

Update the datepicker with given argument or the current input value.

```javascript
$('.datepicker').datepicker('update');
```

### setStartDate

Arguments:

* startDate (String)

Sets a new lower date limit on the datepicker.

```javascript
$('.datepicker').datepicker('setStartDate', '2012-01-01');
```

Omit startDate (or provide an otherwise falsey value) to unset the limit.

```javascript
$('.datepicker').datepicker('setStartDate');
$('.datepicker').datepicker('setStartDate', null);
```

### setEndDate

Arguments:

* endDate (String)

Sets a new upper date limit on the datepicker.

```javascript
$('.datepicker').datepicker('setEndDate', '2012-12-31');
```

Omit endDate (or provide an otherwise falsey value) to unset the limit.

```javascript
$('.datepicker').datepicker('setEndDate');
$('.datepicker').datepicker('setEndDate', null);
```

### setDaysOfWeekDisabled

Arguments:

* daysOfWeekDisabled (String|Array)

Sets the days of week that should be disabled.

```javascript
$('.datepicker').datepicker('setDaysOfWeekDisabled', [0,6]);
```

Omit daysOfWeekDisabled (or provide an otherwise falsey value) to unset the disabled days.

```javascript
$('.datepicker').datepicker('setDaysOfWeekDisabled');
$('.datepicker').datepicker('setDaysOfWeekDisabled', null);
```

## Events

Datepicker class exposes a few events for manipulating the dates.

### show

Fired when the date picker is displayed.

### hide

Fired when the date picker is hidden.

### changeDate

Fired when the date is changed.

```javascript
$('#date-end')
    .datepicker()
    .on('changeDate', function(ev){
        if (ev.date.valueOf() < date-start-display.valueOf()){
            ....
        }
    });
```

### changeYear

Fired when the *view* year is changed from decade view.

### changeMonth

Fired when the *view* month is changed from year view.

## Keyboard support

The datepicker includes some keyboard navigation:

### up, down, left, right arrow keys

By themselves, left/right will move backward/forward one day, up/down will move back/forward one week.

With the shift key, up/left will move backward one month, down/right will move forward one month.

With the ctrl key, up/left will move backward one year, down/right will move forward oone year.

Shift+ctrl behaves the same as ctrl -- that is, it does not change both month and year simultaneously, only the year.

### escape

The escape key can be used to hide and re-show the datepicker; this is necessary if the user wants to manually edit the value.

### enter

When the picker is visible, enter will simply hide it.  When the picker is not visible, enter will have normal effects -- submitting the current form, etc.

## I18N

The plugin supports i18n for the month and weekday names and the `weekStart` option.  The default is English ('en'); other available translations are avilable in the `js/locales/` directory, simply include your desired locale after the plugin.  To add more languages, simply add a key to `$.fn.datepicker.dates`, before calling `.datepicker()`.  Example:

```javascript
$.fn.datepicker.dates['en'] = {
    days: ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"],
    daysShort: ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"],
    daysMin: ["Su", "Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"],
    months: ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"],
    monthsShort: ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"],
    today: "Today"
};
```

Right-to-left languages may also include `rtl: true` to make the calendar display appropriately.

If your browser (or those of your users) is displaying characters wrong, chances are the browser is loading the javascript file with a non-unicode encoding.  Simply add `charset="UTF-8"` to your `script` tag:

```html
<script type="text/javascript" src="bootstrap-datepicker.XX.js" charset="UTF-8"></script>
```

```javascript
$('.datepicker').datepicker({
    language: XX    //as you defined in bootstrap-datepicker.XX.js
});
```
